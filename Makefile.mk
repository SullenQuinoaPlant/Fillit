NAME = fillit.exe
TARGETS = \
		dummy_main\
		my_arrange_tminos_arr\
		my_check_input\
		my_usage\

SRC = ./sources
OBJ = ./objects
OBJS := $(patsubst %,$(OBJ)/%.o,$(TARGETS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror



##########
#DEFAULT :

.PHONY : all
all : $(NAME)




########
#BUILD :

$(NAME) : $(OBJS)
#	echo $$LIBRARY_PATH
#	echo $$LD_LIBRARY_PATH
#	echo $$CPATH
	$(CC) $(CFLAGS)\
		$(OBJS)\
		-lft\
	 	-o $(NAME) 

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<





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
