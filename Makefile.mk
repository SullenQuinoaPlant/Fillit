NAME = fillit.exe
TARGETS = \
		main\
		my_arrange_tminos_arr\
		my_check_input\
		my_print_stack\
		my_stack_tminos_1\
		my_usage

SRC = ./sources
OBJ = ./objects
OBJS := $(patsubst %,$(OBJ)/%.o,$(TARGETS))


CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifndef ROOT
	CSEARCHES = -I . -L .
endif



##########
#DEFAULT :

.PHONY : all
all : $(NAME)




########
#BUILD :

$(NAME) : libft.a libft.h $(OBJS)
	$(CC) $(CFLAGS)\
		$(CSEARCHES)\
		$(OBJS)\
		-lft\
	 	-o $(NAME) 

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) $(CSEARCHES) -c -o $@ $<

libft.a libft.h : libft
	-@if [ -d libft ]; then\
		make -C libft/;\
		cp libft/libft.h .;\
		cp libft/libft.a .;\
	fi

libft :
	@:

################
#MISCELLANEOUS :

.PHONY : clean
clean :
	-rm $(OBJS)

.PHONY : fclean
fclean : clean
	-rm $(NAME)

.PHONY : re
re : fclean all

.PHONY : list_objs
list_objs :
	@echo "objects to be built are : $(OBJS)"
