SRC_DIR = ..
TEST_OBJS := $(SRCS:.c=.test.o)
BUILD_STAMPS := (TEST_OBJS:.o=.o.stamp)

CC = gcc
CFLAGS = -fno-builtin -Wall -Wextra -Werror


.PHONY : all list_tests build_tests run_tests
.SECONDARY : $(SRCS:.c=.test.c)

all : build_tests run_tests


list_tests :
	echo $(TEST_OBJS)


build_tests : $(TEST_OBJS) | cmocka


cmocka :
	

%.test.o : %.test.c $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) \
		-D main=testee_main \
		-include $(SRC_DIR)/$*.c \
		-o $@ \
		$<
	touch "$@"".stamp"


%.test.c :
	cp no_test.c $@
	touch $@


run_tests : $(BUILD_STAMPS)
	touch run_tests


%.test.o.stamp :
	-./$*.test.o
