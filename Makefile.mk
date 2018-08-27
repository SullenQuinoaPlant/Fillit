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
	-rm $(LIB_DIR)/was_liba
	-rm $(LIB_DIR)/was_libso
	-rm $(LIB_DIR)/is_liba
	-rm $(LIB_DIR)/is_libso


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
