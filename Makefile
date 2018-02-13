##############################
#SET PROJECT NAVIGATION VARS :

DEPTH = .
include make_vars.mk


######################
#INCLUDED  MAKEFILES :

include Makefile.mk

libfillit.a : $(OBJS)
	ar -rcs $@ $(OBJS)
	mv libfillit.a libs/lib 



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
