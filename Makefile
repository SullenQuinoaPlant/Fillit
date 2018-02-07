include Makefile.mk


SRCS := $(OBJS:%.o=%.c)
export SRCS

.PHONY : unit-tests ut
unit-tests ut :
	make -C unit-tests

.PHONY : all_unit-tests aut
all_unit-tests aut :
	make -C unit-tests all
