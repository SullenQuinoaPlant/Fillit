NAME = fillit
TARGETS = \
		main\
		my_arrange_tminos_arr\
		my_check_input\
		my_print_stack\
		my_stack_tminos_1\
		my_stack_tminos_2\
		my_stack_tminos_3\
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
CFLAGS_MORE =



##########
#DEFAULT :

.PHONY : all
all : $(NAME)




########
#BUILD :

$(NAME) : $(LIB_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(CFLAGS_MORE)\
		$(CLOADS)\
		$(OBJS)\
		-lft\
	 	-o $(NAME) 

$(OBJ)/%.o : $(SRC)/%.c
	@echo "$$(pwd)/$*"
	$(CC) $(CFLAGS) $(CFLAGS_MORE) $(CINCLUDES) -c -o $@ $<

$(SRC)/%.c : $(LIB_H_DIR)/libft.h
	@:

$(LIB_DIR)/libft.a $(LIB_H_DIR)/libft.h :
	if ! [ -d libft ]; then\
			git clone -b the_lib --single-branch https://github.com/SullenQuinoaPlant/Libft.git ./libft;\
	fi
	make -C libft/ all clean &&\
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
	-rm $(LIB_H_DIR)/*.h
	-rm $(LIB_DIR)/*.a $(LIB_DIR)/*.o

.PHONY : re
re : fclean all

.PHONY : list_objs
list_objs :
	@echo "objects to be built are : $(OBJS)"
