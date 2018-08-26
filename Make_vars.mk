NAME = fillit

LIB_DIR = $(ROOT)/libs/
LIB_OBJ_DIR = $(LIB_DIR)/objects
LIB_H_DIR = $(LIB_DIR)/include
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
