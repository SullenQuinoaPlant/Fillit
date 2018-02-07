TEST_OBJS := $(addprefix test_, $(SRCS:.c=.o))
SRC_DIR = ..

CC = gcc
CFLAGS = -g -fno-builtin -Wall -Wextra -Werror

all : build_tests

.PHONY : all


list_tests :
	echo $(TEST_OBJS)

.PHONY : list_tests


build_tests : $(TEST_OBJS) | cmocka

.PHONY : tests


cmocka :
	

test_%.o : test_%.c $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $<
	touch "$@"".stamp"


test_%.c :



run_tests : 
