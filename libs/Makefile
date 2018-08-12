ifndef ROOT
	ROOT = ..
	include $(ROOT)/Make_vars.mk
endif

libft:
	git clone\
		--single-branch\
		-b the_lib\
		--depth 1\
		https://github.com/SullenQuinoaPlant/Libft.git\
		$(LIB_DIR)/$@/
	$(MAKE) -C $(LIB_DIR)/$@
	cp $(LIB_DIR)/$@/$@.h $(LIB_H_DIR)/
	cp $(LIB_DIR)/$@/$@.a $(LIB_OBJ_DIR)/
	rm -rf $(LIB_DIR)/$@
