# ./generator [n] [q] [plim] [clim] [wlim] [seed]
for((i=1;;++i)); do
	echo ${i};
	./generator 1000 1000 1000000000 $i > in;
	./validator < in;
	./bruteforce < in > out_bruteforce;
	./segment_tree < in > out_sgt;
	(diff -w out_bruteforce out_sgt > dump) || break;
done