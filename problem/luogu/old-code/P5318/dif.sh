#!/bin/bash

for i in {1..10000}; do
	printf "\r$i"
	./r.out >in # 数据生成
	./main.out <in >out1
	./std.out <in >out2
	diff out1 out2 || exit 1
done

