utils_test: utils_test.c utils.o
	gcc utils_test.c utils.o -o utils_test

utils.o: utils.c utils.h
	gcc -c utils.c

clean:
	rm utils_test utils.o
