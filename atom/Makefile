objects = atom_test.o atom.o

atom_test: $(objects)
	gcc $(objects) -o atom_test

atom.o: atom.h

.PHONY : clean

clean:
	rm atom_test $(objects)
