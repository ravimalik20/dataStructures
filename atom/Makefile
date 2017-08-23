atom_test: atom_test.c atom.o
	gcc atom_test.c atom.o -o atom_test

atom.o: atom.c atom.h
	gcc -c atom.c

clean:
	rm atom_test atom.o
