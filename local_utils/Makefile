objects = utils_test.o utils.o

utils_test: $(objects)
	gcc $(objects) -o utils_test

utils.o: utils.h

.PHONY: clean

clean:
	rm utils_test $(objects)
