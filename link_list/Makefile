objects = link_list_test.o link_list.o

link_list_test: $(objects)
	gcc $(objects) -o link_list_test

link_list.o: link_list.h

.PHONY: clean

clean:
	rm link_list_test $(objects)
