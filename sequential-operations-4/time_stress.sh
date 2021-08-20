# ./generator [n] [q] [plim] [clim] [wlim] [seed]
for((i=0;;++i)); do
	echo ${i};
	./generator 100000 100000 10 3 1000000000 ${i} > in234798234;
	./validator < in234798234;
	time ./segment_tree < in234798234 > out_sgt49350934;
done