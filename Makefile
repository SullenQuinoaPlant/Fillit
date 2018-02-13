include Makefile.mk

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




##############
#MISCELLANEOUS


libfillit.a : $(OBJS)
	ar -rcs $@ $(OBJS)
	mv libfillit.a $(OBJ)
