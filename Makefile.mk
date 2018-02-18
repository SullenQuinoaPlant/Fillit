NAME = fillit
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


ifndef ROOT
	LIB_DIR = ./libs
	LIB_H_DIR = ./libs
endif
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CSEARCHES = -L $(LIB_DIR) -I $(LIB_H_DIR)



##########
#DEFAULT :

.PHONY : all
all : $(NAME)




########
#BUILD :

$(NAME) : $(LIB_DIR)/libft.a $(LIB_H_DIR)/libft.h $(OBJS)
	@echo $$(pwd)
	$(CC) $(CFLAGS)\
		$(CSEARCHES)\
		$(OBJS)\
		-lft\
	 	-o $(NAME) 

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) $(CSEARCHES) -c -o $@ $<

$(LIB_DIR)/libft.a $(LIB_H_DIR)/libft.h :
	if ! [ -d libft ]; then\
			git clone -b the_lib --single-branch https://github.com/SullenQuinoaPlant/Libft.git ./libft;\
	fi
	make -C libft/ &&\
	cp libft/libft.h $(LIB_H_DIR) &&\
	cp libft/libft.a $(LIB_DIR) &&\
	rm -rf libft;\


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
