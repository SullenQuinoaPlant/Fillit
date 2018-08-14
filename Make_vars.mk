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
		my_arrange_tminos_arr\
		my_check_input\
		my_print_stack\
		my_stack_tminos\
		my_usage

OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))
