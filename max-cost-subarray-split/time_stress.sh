for((i=0;;++i)); do
	echo ${i};
	./generator 5 100000 50000 -10000 10000 ${i} > in;
	./validator < in;
	time ./segment_tree < in > out_sgt;
done