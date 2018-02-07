include Makefile.mk


SRCS := $(OBJS:%.o=%.c)
export SRCS

.PHONY : unit-tests ut
unit-tests ut :
	make -C unit-tests



.PHONY : git-push gp
git-push gp :
	git status
	git commit -a -m incremental
	git push
