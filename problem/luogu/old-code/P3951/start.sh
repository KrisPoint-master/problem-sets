for i in {1..10}; do
  for j in {1..10}; do
    ./main.out <"data/$((i * 10 + j)).in"
  done
done
