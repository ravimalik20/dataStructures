utils_test: utils_test.o utils.o
	gcc utils_test.o utils.o -o utils_test

utils_test.o: utils_test.c
	gcc -c utils_test.c

utils.o: utils.c utils.h
	gcc -c utils.c

clean:
	rm utils_test utils.o utils_test.o
