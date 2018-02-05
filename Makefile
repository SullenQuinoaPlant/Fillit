include Makefile.mk

unit-tests ut :
	export OBJS=$(OBJS)
	make -C unit-tests

.PHONY : unit-tests ut
