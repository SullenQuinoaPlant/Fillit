include Makefile.mk

export OBJS
unit-tests ut :
	make -C unit-tests

.PHONY : unit-tests ut

push :
	git status
	git commit -a -m increment
	git push

.PHONY : push
