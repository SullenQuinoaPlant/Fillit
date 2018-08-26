NAME = fillit

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
