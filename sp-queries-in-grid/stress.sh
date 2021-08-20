for((i=0;;++i)); do
	echo ${i};
	./generator 5 100000 1 -10000 10000 ${i} > in;
	./validator < in;
	./bruteforce < in > out_bruteforce;
	./segment_tree < in > out_sgt;
	(diff -w out_bruteforce out_sgt > dump) || break;
done