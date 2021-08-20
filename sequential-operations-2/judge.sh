for f in ./input/*.txt; do
	echo $f;
	foo=${f#./E/in/};
	time ./segment-tree < $f > out_main;
	./bruteforce < $f > out_bruteforce;
	(diff -w out_main out_bruteforce > dump) || break
done
