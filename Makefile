include Makefile.mk


SRCS := $(OBJS:%.o=%.c)
export SRCS

unit-tests ut :
	make -C unit-tests

.PHONY : unit-tests ut


git-push gp :
	git status
	git commit -a -m incremental
	git push

.PHONY : git-push gp
