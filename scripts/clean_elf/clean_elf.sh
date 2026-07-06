#!/bin/bash

# 清除当前目录及其子目录下的 ELF 可执行文件

echo "开始扫描当前目录下的 ELF 可执行文件..."

find . -type f -print0 | while IFS= read -r -d '' file; do
    # 判断文件是否为 ELF 可执行文件
    if file "$file" | grep -qE 'ELF .* executable|ELF .* pie executable'; then
        echo "删除: $file"
        rm -f "$file"
    fi
done

echo "清理完成。"