LIB_DIR = $(ROOT)/libs/lib
LIB_H_DIR = $(ROOT)/libs/include
SRC_DIR = $(ROOT)/sources

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CINCLUDES = -I $(LIB_H_DIR)
CLOADS = -L $(LIB_DIR)
