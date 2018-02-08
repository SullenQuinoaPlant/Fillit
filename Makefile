include Makefile.mk


libfillit.a : all
	ar -rcs $@ $(OBJS)




########
#TESTS :


SRCS := $(OBJS:%.o=%.c)
export SRCS

.PHONY : unit-tests ut
unit-tests ut : all libfillit.a
	make -C unit-tests

.PHONY : all_unit-tests aut
all_unit-tests aut : all libfillit.a
	make -C unit-tests all
