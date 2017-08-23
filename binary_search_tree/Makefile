bstree_test: bstree_test.o bstree.o
	gcc bstree_test.o bstree.o -o bstree_test

bstree_test.o: bstree_test.c
	gcc -c bstree_test.c

bstree.o: bstree.c bstree.h
	gcc -c bstree.c

clean:
	rm bstree_test bstree.o bstree_test.o
