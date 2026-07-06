import os
import re
import sys
import argparse
import json
import yaml
import requests
from bs4 import BeautifulSoup

PROBLEM_DIR = os.path.join(os.path.dirname(__file__), "..", "..", "problem", "luogu")
LUOGU_URL = "https://www.luogu.com.cn/problem/{problem_id}"


def fetch_page_data(problem_id):
    url = LUOGU_URL.format(problem_id=problem_id)
    r = requests.get(url, timeout=10, headers={
        "User-Agent": "Mozilla/5.0 (compatible; create.py)"
    })
    r.raise_for_status()
    m = re.search(r'<script id="lentille-context" type="application/json">(.*?)</script>', r.text, re.DOTALL)
    if not m:
        return None
    return json.loads(m.group(1))


def fetch_title(problem_id):
    try:
        data = fetch_page_data(problem_id)
        if data:
            name = data["data"]["problem"]["name"]
            if name:
                return name
    except Exception:
        pass
    return None


def fetch_similar_problems(problem_id):
    try:
        data = fetch_page_data(problem_id)
        if data:
            recommendations = data["data"].get("recommendations", [])
            return [r["pid"] for r in recommendations if r.get("pid")]
    except Exception:
        pass
    return []


def build_problem_md(data):
    problem = data["data"]["problem"]
    contenu = problem.get("contenu") or problem.get("content", {})
    title = contenu.get("name", problem.get("name", ""))
    background = contenu.get("background", "").strip()
    description = contenu.get("description", "").strip()
    formatI = contenu.get("formatI", "").strip()
    formatO = contenu.get("formatO", "").strip()
    hint = contenu.get("hint", "").strip()
    samples = problem.get("samples", [])

    lines = []
    lines.append(f"# {title}")
    lines.append("")

    if background:
        lines.append("## 题目背景")
        lines.append("")
        lines.append(background)
        lines.append("")

    lines.append("## 题目描述")
    lines.append("")
    lines.append(description)
    lines.append("")

    lines.append("## 输入格式")
    lines.append("")
    lines.append(formatI)
    lines.append("")

    lines.append("## 输出格式")
    lines.append("")
    lines.append(formatO)
    lines.append("")

    for i, (inp, out) in enumerate(samples, 1):
        lines.append(f"## 输入输出样例 #{i}")
        lines.append("")
        lines.append("**输入**")
        lines.append("```")
        lines.append(inp.rstrip("\n"))
        lines.append("```")
        lines.append("")
        lines.append("**输出**")
        lines.append("```")
        lines.append(out.rstrip("\n"))
        lines.append("```")
        lines.append("")

    if hint:
        lines.append("## 提示")
        lines.append("")
        lines.append(hint)
        lines.append("")

    return "\n".join(lines).strip() + "\n"


def prompt(label, default=None):
    if default is not None:
        prompt_text = f"{label} (default={default}): "
    else:
        prompt_text = f"{label}: "
    val = input(prompt_text).strip()
    if not val and default is not None:
        return default
    return val


def write_yaml(dirpath, data):
    os.makedirs(dirpath, exist_ok=True)
    filepath = os.path.join(dirpath, "head.yaml")
    with open(filepath, "w", encoding="utf-8") as f:
        yaml.dump(data, f, allow_unicode=True, default_flow_style=False, sort_keys=False)
    return filepath


def write_file(dirpath, filename, content):
    filepath = os.path.join(dirpath, filename)
    with open(filepath, "w", encoding="utf-8") as f:
        f.write(content)
    return filepath


def main():
    parser = argparse.ArgumentParser(description="创建 Luogu 题目目录及 head.yaml、problem.md")
    parser.add_argument("problem_id", help="题目 ID，如 P1002")
    parser.add_argument("--title", "-t", help="题目标题")
    parser.add_argument("--tags", "-T", help="标签，逗号分隔")
    parser.add_argument("--desc", "-d", help="题目描述")
    parser.add_argument("--difficulty", "-D", help="难度")
    parser.add_argument("--common", "-c", help="相似题目 ID，逗号分隔")
    parser.add_argument("--force", "-f", action="store_true", help="目录存在时直接覆盖，不询问")
    parser.add_argument("--no-problem-md", action="store_true", help="不抓取 problem.md")
    args = parser.parse_args()

    problem_id = args.problem_id.upper()
    if not re.match(r"^P\d+$", problem_id):
        print("错误：题目 ID 格式应为 P 加数字，如 P1002")
        sys.exit(1)

    dirpath = os.path.join(PROBLEM_DIR, problem_id)

    if os.path.exists(dirpath):
        if args.force:
            print(f"目录已存在，因 -f 参数直接覆盖")
        else:
            ans = input(f"目录 {os.path.relpath(dirpath, os.path.join(os.path.dirname(__file__), '..'))} 已存在，覆盖? (y/N): ").strip().lower()
            if ans != "y":
                print("已取消")
                return

    has_cli_flag = any(getattr(args, f) is not None for f in ["title", "tags", "desc", "difficulty"])
    interactive = not has_cli_flag

    data = {
        "oj": "luogu",
        "problem": problem_id,
    }

    if interactive:
        fetched = fetch_title(problem_id)
        if fetched:
            print(f"自动获取标题: {fetched}")
        title = prompt("title", default=fetched or "")
        raw_tags = prompt("tags (逗号分隔)")
        desc = prompt("description")
        diff = prompt("difficulty")
    else:
        title = args.title if args.title is not None else ""
        raw_tags = args.tags if args.tags is not None else ""
        desc = args.desc if args.desc is not None else ""
        diff = args.difficulty if args.difficulty is not None else ""

    data["title"] = title
    tags = [t.strip() for t in raw_tags.split(",") if t.strip()] if raw_tags else []
    data["tags"] = tags
    data["description"] = desc
    data["difficulty"] = diff
    data["source"] = LUOGU_URL.format(problem_id=problem_id)

    fetched_common = fetch_similar_problems(problem_id)
    if interactive:
        if fetched_common:
            print(f"自动获取相似题目: {', '.join(fetched_common)}")
        elif fetched_common is not None:
            print("该题目暂无相似推荐")
        common_raw = prompt("common (逗号分隔)", default=",".join(fetched_common) if fetched_common else "")
        common = [c.strip() for c in common_raw.split(",") if c.strip()] if common_raw else []
    else:
        if args.common is not None:
            common_raw = args.common
        elif fetched_common:
            common_raw = ",".join(fetched_common)
            print(f"自动获取相似题目: {common_raw}")
        else:
            print("错误: 无法自动获取相似题目，请手动输入")
            common_raw = input("common (逗号分隔): ").strip()
        common = [c.strip() for c in common_raw.split(",") if c.strip()] if common_raw else []
    data["common"] = common

    os.makedirs(dirpath, exist_ok=True)
    yaml_path = write_yaml(dirpath, data)
    print(f"已创建: {os.path.relpath(yaml_path, os.path.join(os.path.dirname(__file__), '..'))}")

    if not args.no_problem_md:
        try:
            page_data = fetch_page_data(problem_id)
            if page_data:
                md = build_problem_md(page_data)
                md_path = write_file(dirpath, "problem.md", md)
                print(f"已创建: {os.path.relpath(md_path, os.path.join(os.path.dirname(__file__), '..'))}")
            else:
                print("警告: 无法解析页面数据，跳过 problem.md")
        except Exception as e:
            print(f"警告: 抓取 problem.md 失败 ({e})，跳过")


if __name__ == "__main__":
    main()
