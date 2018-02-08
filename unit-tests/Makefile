SRC_DIR = ..
TEST_SRCS :=
TEST_SRCS += $(shell \
	for i in $(SRCS:.c=.test.c); do\
		if [ -f $$i ]; then srcs="$$srcs $$i"; fi;\
	done; echo $$srcs;)
TEST_OBJS := $(TEST_SRCS:.c=.o)
BUILD_STAMPS := $(TEST_OBJS:.o=.o.stamp)

CC = gcc
CFLAGS = -fno-builtin -Wall -Wextra -Werror




.PHONY : test
test : list_tests build_tests run_tests




############
#BUILD TESTS

.PHONY : build_tests
build_tests : $(TEST_OBJS) | cmocka


cmocka :
	

%.test.o : %.test.c $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) \
		-L $(SRC_DIR) -I $(SRC_DIR)\
		-D main=testee_main \
		-include $(SRC_DIR)/$*.c \
		-o $@ \
		$< -lfillit; touch $@.stamp


%.test.c :
	@:




############
#RUN TESTS :

.PHONY : run_tests
run_tests : test_execution.stamp


test_execution.stamp : $(BUILD_STAMPS) 
	@for i in $(basename $?); do\
		if [ -f $$i ]; then ./$$i; fi;\
	done
	touch test_execution.stamp


$(BUILD_STAMPS) :
	@:




###############
#MISCELLANEOUS:

.PHONY : all
all : clean test



.PHONY : clean
clean :
	-rm *.o
	-rm *.stamp
	touch test_execution.stamp



.PHONY : list_tests
list_tests :
	@echo "list of test sources:"
	@echo $(TEST_SRCS)
