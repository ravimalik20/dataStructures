bstree_test: bstree_test.c bstree.o
	gcc bstree_test.c bstree.o -o bstree_test

bstree.o: bstree.c bstree.h
	gcc -c bstree.c

clean:
	rm bstree_test bstree.o
