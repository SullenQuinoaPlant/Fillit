SRC_DIR = ..
TEST_OBJS := $(SRCS:.c=.test.o)
BUILD_STAMPS := $(TEST_OBJS:.o=.o.stamp)

CC = gcc
CFLAGS = -fno-builtin -Wall -Wextra -Werror



.PHONY : test
test : list_tests build_tests run_tests



.PHONY : list_tests
list_tests :
	@echo "list of test objects:"
	@for i in $(TEST_OBJS); do\
		if [ -f $$i ]; then echo $$i; fi;\
	done
	@echo "\n"



.PHONY : build_tests
build_tests : $(TEST_OBJS) | cmocka


cmocka :
	

%.test.o : %.test.c $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) \
		-D main=testee_main \
		-include $(SRC_DIR)/$*.c \
		-o $@ \
		$<
	touch $@.stamp


.SECONDARY : $(SRCS:.c=.test.c)
#.SECONDARY : %.test.c
%.test.c :
	cp no_test.c $@
	touch $@



.PHONY : run_tests
run_tests : test_execution.stamp


test_execution.stamp : $(BUILD_STAMPS) 
	@for i in $(basename $?); do\
		./$$i;\
	done
	touch test_execution.stamp



.PHONY : clean
clean :
	-rm *.o
	-rm *.stamp
	touch test_execution.stamp



.PHONY : all
all : clean test
