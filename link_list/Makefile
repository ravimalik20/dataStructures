objects = link_list_test.o link_list.o

link_list_test: $(objects)
	gcc $(objects) -o link_list_test

link_list.o: link_list.h

clean:
	rm link_list_test $(objects)
