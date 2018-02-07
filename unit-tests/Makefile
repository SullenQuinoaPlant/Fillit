SRC_DIR = ..
TEST_OBJS := $(SRCS:.c=.test.o)
BUILD_STAMPS := (TEST_OBJS:.o=.o.stamp)

CC = gcc
CFLAGS = -fno-builtin -Wall -Wextra -Werror



.PHONY : all
all : build_tests run_tests


.PHONY : list_tests
list_tests :
	for i in "$TEST_OBJS"; do echo $i;done


.PHONY : build_tests
build_tests : $(TEST_OBJS) | cmocka


cmocka :
	

%.test.o : %.test.c $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) \
		-D main=testee_main \
		-include $(SRC_DIR)/$*.c \
		-o $@ \
		$<
	touch "$@"".stamp"


#.SECONDARY : $(SRCS:.c=.test.c)
.SECONDARY : %.test.c
%.test.c :
	cp no_test.c $@
	touch $@


.PHONY : run_tests
run_tests : $(BUILD_STAMPS)
	touch test_execution.stamp


%.test.o.stamp : test_execution.stamp
	-./$*.test.o
