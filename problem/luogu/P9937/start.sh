#!/bin/bash
for i in {1..1000}
do
    ./random.out > in
    ./baoli.out < in
done
