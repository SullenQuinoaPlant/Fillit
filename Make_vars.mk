NAME = fillit

LIB_DIR = $(ROOT)/libs/
LIB_OBJ_DIR	 = $(LIB_DIR)/objects
LIB_H_DIR = $(LIB_DIR)/include
SRC_DIR = $(ROOT)/sources
OBJ_DIR = $(ROOT)/objects

CC = gcc
CFLAGS_MORE =
CFLAGS = -Wall -Wextra -Werror
CFLAGS += $(CFLAGS_MORE)

TARGETS = \
		main\
		my_arrange_tminos_arr\
		my_arrange_tminos_arr_1\
		my_check_input\
		my_print_stack\
		my_stack_tminos_1\
		my_stack_tminos_2\
		my_stack_tminos_3\
		my_stack_tminos_4\
		my_stack_tminos_5\
		my_stack_tminos_6\
		my_stack_tminos_6_1\
		my_stack_tminos_7\
		my_usage

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))
