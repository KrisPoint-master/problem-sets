#!/bin/bash

for i in {1..100000}; do
	printf "\r$i"
	./r >in # 数据生成
	./1 <in >out1
	./2 <in >out2
	diff out1 out2 || exit 1
done

