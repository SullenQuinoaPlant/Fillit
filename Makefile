include Makefile.mk


#######
#LAZY :


%.c :
	echo yo


########
#TESTS :


#SRCS := $(OBJS:%.o=%.c)
#export SRCS

.PHONY : unit-tests ut
unit-tests ut : libfillit.a
	make -C unit-tests

.PHONY : all_unit-tests aut
all_unit-tests aut : libfillit.a
	make -C unit-tests all




##############
#MISCELLANEOUS


libfillit.a : $(OBJS)
	ar -rcs $@ $(OBJS)
