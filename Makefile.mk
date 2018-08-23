ifndef ROOT
	ROOT = .
	include Make_vars.mk
endif

##########
#DEFAULT :

.PHONY : all
all : $(NAME)


########
#BUILD :

$(NAME) : $(LIB_OBJ_DIR)/libft.a $(OBJS)
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
