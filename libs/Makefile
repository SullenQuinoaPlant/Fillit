ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif

libft:
	git clone\
		--single-branch\
		-b the_lib\
		--depth 1\
		https://github.com/SullenQuinoaPlant/Libft.git\
		$@/
	$(MAKE) -C $@
	cp $@/$@.h $(LIB_H_DIR)/
	cp $@/$@.a $(LIB_OBJ_DIR)/
	rm -rf ./$@
