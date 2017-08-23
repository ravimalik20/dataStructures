objects = atom_test.o atom.o

atom_test: $(objects)
	gcc $(objects) -o atom_test

atom.o: atom.h

clean:
	rm atom_test $(objects)
