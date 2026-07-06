#!/bin/bash

PROBLEM_DIR="$(cd "$(dirname "$0")/../../problem/luogu" && pwd)"
DRY_RUN=0

if [ "$1" = "--dry-run" ]; then
    DRY_RUN=1
fi

files=()
while IFS= read -r -d '' f; do
    files+=("$f")
done < <(find "$PROBLEM_DIR" -type f \( \
    -name "*.zip" -o \
    -name "*.out" -o \
    -name "*.ans" -o \
    -name "*.in" -o \
    -name "out" -o \
    -name "out1" -o \
    -name "out2" -o \
    -name "temp" -o \
    -name "*.temp" \
\) -print0 2>/dev/null)

if [ ${#files[@]} -eq 0 ]; then
    echo "没有需要清理的文件"
    exit 0
fi

if [ $DRY_RUN -eq 1 ]; then
    echo "[DRY-RUN] 将删除以下文件:"
    for f in "${files[@]}"; do
        echo "  ${f#$PROBLEM_DIR/}"
    done
    echo "共 ${#files[@]} 个文件 (DRY-RUN, 未实际删除)"
else
    for f in "${files[@]}"; do
        rm "$f"
        echo "已删除 ${f#$PROBLEM_DIR/}"
    done
    echo "共删除 ${#files[@]} 个文件"
fi
