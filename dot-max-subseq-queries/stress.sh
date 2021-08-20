for((i=0;;++i)); do
	echo ${i};
	./generator 200000 5 100 -100000000 100000000 ${i} > in;
	./validator < in;
	./bruteforce < in > out_bruteforce;
	./segment_tree < in > out_sgt;
	(diff -w out_bruteforce out_sgt > dump) || break;
done