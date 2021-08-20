for((i=1234; ;++i)); do
	./generator 5 10 10 -3 10 ${i} > in;
	./bruteforce < in;
	read line;
done