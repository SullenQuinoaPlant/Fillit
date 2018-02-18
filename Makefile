##############################
#SET PROJECT NAVIGATION VARS :

ROOT = .
include Make_vars.mk


######################
#INCLUDED  MAKEFILES :

include Makefile.mk

libfillit.a : $(OBJS)
	ar -rcs $@ $(OBJS)
	mv libfillit.a libs/lib 
	cp $(SRC)/fillit.h $(LIB_H_DIR)


include Make_vars.mk #in case Makefile.mk sets some options we don't want
include auxilliary/Makefile



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
	cp -r sources/ $@/
	git clone -b the_lib --single-branch https://github.com/SullenQuinoaPlant/Libft.git $@/libft
	mkdir $@/objects
	mkdir $@/libs
	ls -R -1 $@/
