NAME = fillit.exe
TARGETS = check_input
SRC = ./sources
OBJ = ./objects
OBJS = $(addprefix $(OBJ)/,$(TARGETS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean :
	-rm $(OBJS)

fclean : clean
	-rm $(NAME)

re : fclean all

.PHONY : re fclean clean all
