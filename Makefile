include Makefile.mk

SRCS := $($(OBJS):%.o=%.c)
export SRCS

unit-tests ut :
	make -C unit-tests

.PHONY : unit-tests ut
