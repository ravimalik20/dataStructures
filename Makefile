dirs = atom binary_search_tree link_list local_utils

subsys:
	for i in $(dirs); do $(MAKE) -C $$i; done

clean:
	for i in $(dirs); do $(MAKE) clean -C $$i; done

