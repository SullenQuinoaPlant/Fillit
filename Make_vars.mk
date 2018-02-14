LIB_DIR = $(ROOT)/libs/lib
LIB_H_DIR = $(ROOT)/libs/include
SRC_DIR = $(ROOT)/sources

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CSEARCHES = -L $(LIB_DIR) -I $(LIB_H_DIR)
