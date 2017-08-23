link_list_test: link_list_test.c link_list.o
	gcc link_list_test.c link_list.o -o link_list_test

link_list.o: link_list.c link_list.h
	gcc -c link_list.c

clean:
	rm link_list_test link_list.o
