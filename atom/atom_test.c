#include<stdio.h>
#include<string.h>
#include<limits.h>
#include"atom.h"

void main()
{
	char *str1 = "Hello World";
	char *str2 = "Hello World";

	const char *atom1 = Atom_new(str1, strlen(str1));
	const char *atom2 = Atom_string(str2);

	printf("Str1 address: %p\n", str1);
	printf("Str2 address: %p\n", str2);
	printf("Atom1 address: %p\n", atom1);
	printf("Atom2 address: %p\n", atom2);

	printf("It's funny how the string representations of C also have the same address.\n");

	printf("Atom1 length: %d\n", Atom_length(atom1));
	printf("Atom2 length: %d\n", Atom_length(atom2));

	const char *atom3 = Atom_int(1L);
	const char *atom4 = Atom_int(LONG_MIN);

	printf("Atom3 address: %p\n", atom3);
	printf("Atom4 address: %p\n", atom4);
	printf("Atom3 length: %d\n", Atom_length(atom3));
	printf("Atom4 length: %d\n", Atom_length(atom4));

	puts(atom3);
	puts(atom4);
}

