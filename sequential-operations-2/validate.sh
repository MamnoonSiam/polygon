for f in ./input/*.txt; do
	echo $f;
	./validator < $f;
done
