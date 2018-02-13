SRC_DIR = ../sources
TEST_SRCS := $(wildcard *.test.c)
#TEST_SRCS += $(shell \
#	for i in $(SRCS:.c=.test.c); do\
#		if [ -f $$i ]; then srcs="$$srcs $$i"; fi;\
#	done; echo $$srcs;)
TEST_OBJS := $(TEST_SRCS:.c=.o)

#CMOCKA_DIR := $(shell echo $$(pwd)/cmocka)
CMOCKA_DIR := ./cmocka

FILLIT_DIR = ..

CC = gcc
CFLAGS = -fno-builtin #-Wall -Wextra -Werror
COMMON_SEARCH_PATHS =\
		-L $(SRC_DIR) -I $(SRC_DIR)\
		-L $(CMOCKA_DIR) -I $(CMOCKA_DIR)\
		-L $(FILLIT_DIR)
COMMON_LIBS =\
		-lfillit -lft -lcmocka

BUILD_STAMPS := $(TEST_OBJS:.o=.build.stamp)
EXECUTION_STAMPS := $(TEST_OBJS:.o=.execution.stamp)



.PHONY : test
test : list_tests build_tests run_tests




############
#BUILD TESTS

.PHONY : build_tests
build_tests : cmocka $(TEST_OBJS)

.PHONY : cmocka
cmocka : 
	if $(CC) $(CFLAGS) boilerplate.c -lcmocka -o test.o; then\
		rm test.o;\
		echo "cmocka already installed";\
	else\
		$(MAKE) -C cmocka/ >/dev/null;\
	fi

%.test.o : %.test.c $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(COMMON_SEARCH_PATHS)\
		-D main=testee_main\
		-include $(SRC_DIR)/$*.c\
		$<\
		$(COMMON_LIBS)\
		-o $@\
		-Wl,-rpath=$(CMOCKA_DIR);\
		touch $*.test.build.stamp

%.test.o : %.test.c
	@$(CC) $(CFLAGS) $(COMMON_SEARCH_PATHS)\
		$<\
		$(COMMON_LIBS)\
		-o $@\
		-Wl,-rpath=$(CMOCKA_DIR);\
		touch $*.test.build.stamp

%.test.c : $(CMOCKA_DIR)/my_macro_overlay.h




############
#RUN TESTS :

.PHONY : run_tests
#run_tests : test_execution.stamp
run_tests : $(EXECUTION_STAMPS)


%.execution.stamp : %.build.stamp
	./$*.o
	touch $@

#the following clutters less with stamp files but prevents the concurrent execution of tests
# (whatever)
#test_execution.stamp : $(BUILD_STAMPS) 
#	@for i in $(basename $?); do\
#		if [ -f $$i ]; then ./$$i; fi;\
#	done
#	touch test_execution.stamp

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
	@echo "list of test objects:"
	@echo $(TEST_OBJS)
