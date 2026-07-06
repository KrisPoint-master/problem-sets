#!/bin/bash

for i in {1..10000}; do
	printf "\r$i"
	./r >in # 数据生成
	./main <in >out1
	./5 <in >out2
	diff out1 out2 || exit 1
done
