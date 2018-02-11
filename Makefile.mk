NAME = fillit.exe
TARGETS = dummy_main \
			check_input
SRC = ./sources
OBJ = ./objects
OBJS := $(patsubst %,$(OBJ)/%.o,$(TARGETS))
#OBJS := $($(addprefix $(OBJ)/,$(TARGETS)):%=%.o)
#OBJS := $($(addsuffix .o,$(OBJS)):%=%.o)
#OBJS := $($(TARGETS):%=$(OBJ)/%.o)

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
