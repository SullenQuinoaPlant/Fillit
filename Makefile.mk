NAME = fillit.exe
TARGETS = \
		check_input\
		dummy_main\
		usage
SRC = ./sources
OBJ = ./objects
OBJS := $(patsubst %,$(OBJ)/%.o,$(TARGETS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror



##########
#DEFAULT :

.PHONY : all
all : list_objs list_objs $(NAME) list_objs 




########
#BUILD :

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

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
