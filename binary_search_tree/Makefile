objects = bstree_test.o bstree.o

bstree_test: $(objects)
	gcc $(objects) -o bstree_test

bstree.o: bstree.h

.PHONY: clean

clean:
	rm bstree_test $(objects)
