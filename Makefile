#ifndef ROOT
	ROOT = .
#endif

include $(ROOT)/Make_vars.mk

include $(ROOT)/Makefile.mk

libfillit.a : $(OBJS)
	ar -rcs $@ $(OBJS)
	mv libfillit.a $(LIB_OBJ_DIR)/
	cp $(SRC_DIR)/fillit.h $(LIB_H_DIR)/


include $(ROOT)/auxilliary/Makefile



########
#TESTS :

#SRCS := $(OBJS:%.o=%.c)
#export SRCS

.PHONY : unit-tests ut
unit-tests ut : libfillit.a libaux.a
	make -C unit-tests

.PHONY : all_unit-tests aut
all_unit-tests aut : libfillit.a libaux.a
	make -C unit-tests all



################
#CLEAN PROJECT :

.PHONY : clean_fillit
clean_fillit : 
	-rm -rf $@/
	mkdir $@
	cp auteur $@/
	cp Makefile.mk $@/Makefile
	cp Make_vars_release.mk $@/Make_vars.mk
	git clone -b the_lib --single-branch https://github.com/SullenQuinoaPlant/Libft.git $@/libft
	mkdir $@/objects
	mkdir $@/sources
	cp -r sources/ $@
	mkdir $@/libs
	ls -R -1 $@/
