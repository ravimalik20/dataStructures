atom_test: atom_test.o atom.o
	gcc atom_test.o atom.o -o atom_test

atom_test.o: atom_test.c
	gcc -c atom_test.c

atom.o: atom.c atom.h
	gcc -c atom.c

clean:
	rm atom_test atom.o atom_test.o
