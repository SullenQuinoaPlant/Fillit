NAME = fillit.exe
TARGETS = dummy_main \
			check_input
SRC = ./sources
OBJ = ./objects
OBJS := $(patsubst %,$(OBJ)/%.o,$(TARGETS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : list_objs $(NAME)

.PHONY : list_objs
list_objs :
	@echo "objects to be built are : $(OBJS)"

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -o $@ $<
	ls $(OBJ)

clean :
	-rm $(OBJS)

fclean : clean
	-rm $(NAME)

re : fclean all

.PHONY : re fclean clean all
