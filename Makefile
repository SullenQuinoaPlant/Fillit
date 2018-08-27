NAME = fillit

ROOT = .
LIB_DIR = $(ROOT)/libft
LIB_OBJ_DIR = $(LIB_DIR)/
LIB_H_DIR = $(LIB_DIR)/
SRC_DIR = $(ROOT)/sources
OBJ_DIR = $(ROOT)/objects

CC = gcc
CFLAGS_MORE =
CFLAGS := -Wall -Wextra -Werror
CFLAGS += $(CFLAGS_MORE)

TARGETS = \
		main\
		arrange_tminos\
		check_input\
		compare_best\
		print_stack\
		stack_tminos\
		usage

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

CLEANABLE = $(OBJS) $(LIB_DIR)/*.o
FCLEANABLE = $(NAME) $(LIB_DIR)/libft.a
##########
#DEFAULT :

.PHONY : all
all : $(NAME)


########
#BUILD :

$(NAME) : $(OBJ_DIR) $(LIB_OBJ_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS)\
		-L $(LIB_OBJ_DIR)\
		$(OBJS)\
		-L ./$(LIB_DIR)\
		-lft\
	 	-o $(NAME) 

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-I $(LIB_H_DIR)\
		-c -o $@ $<

$(LIB_OBJ_DIR)/libft.a $(LIB_H_DIR)/libft.h :
	$(MAKE) -C $(LIB_DIR)
	-rm $(LIB_DIR)/was_liba
	-rm $(LIB_DIR)/was_libso
	-rm $(LIB_DIR)/is_liba
	-rm $(LIB_DIR)/is_libso

$(OBJ_DIR) :
	mkdir $@

################
#MISCELLANEOUS :

.PHONY : clean
clean :
	-rm $(CLEANABLE)

.PHONY : fclean
fclean : clean
	-rm $(FCLEANABLE)

.PHONY : re
re : fclean all

.PHONY : list_objs
list_objs :
	@echo "objects to be built are : $(OBJS)"
