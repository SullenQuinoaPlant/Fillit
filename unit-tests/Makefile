SRC_DIR = ../sources
TEST_SRCS := $(wildcard *.test.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)

CMOCKA_DIR := ./cmocka
LIBLIBERTY_DIR := ./libliberty
LIBS_DIR = ../libs/lib
LIBS_H_DIR = ../libs/include

CC = gcc
CFLAGS_MORE =
CFLAGS = -fno-builtin #-Wall -Wextra -Werror
CFLAGS += $(CFLAGS_MORE)
COMMON_SEARCH_PATHS =\
		-I $(SRC_DIR)\
		-L $(LIBS_DIR) -I $(LIBS_H_DIR)\
		-L $(CMOCKA_DIR) -I $(CMOCKA_DIR)\
#		-L $(LIBLIBERTY_DIR) -I$(LIBLIBERTY_DIR)

COMMON_LIBS =\
		-laux -lfillit -lft -lcmocka #-liberty

GCC_LD_OPTS =\
		-Wl,-rpath=$(LIBS_DIR)\
		-Wl,-rpath=$(CMOCKA_DIR)

BUILD_STAMPS := $(TEST_OBJS:.o=.build.stamp)
EXECUTION_STAMPS := $(TEST_OBJS:.o=.execution.stamp)



##########
#DEFAULT :

.PHONY : test
test : list_tests build_tests run_tests




############
#BUILD TESTS

.PHONY : build_tests
build_tests : cmocka $(TEST_OBJS)

.PHONY : cmocka
cmocka : 
	@if $(CC) $(CFLAGS) $(COMMON_SEARCH_PATHS)\
		 test_cmocka.c -lcmocka -o test.o; then\
		rm test.o;\
		echo "cmocka already installed";\
	else\
		$(MAKE) -C $(CMOCKA_DIR) >/dev/null;\
	fi

.PHONY : libliberty #could not find a way to get it short of installing gcc. and that's a mouthful for another day
libliberty :
	@if $(CC) $(CFLAGS) $(COMMON_SEARCH_PATHS)\
		 test_libliberty.c -liberty -o test.o; then\
		rm test.o;\
		echo "libliberty already installed";\
	else\
		$(MAKE) -C $(LIBLIBERTY_DIR) >/dev/null;\
	fi

%.test.o : %.test.c $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(COMMON_SEARCH_PATHS)\
		-D main=testee_main\
		-include $(SRC_DIR)/$*.c\
		$<\
		$(COMMON_LIBS)\
		-o $@\
		$(GCC_LD_OPTS);
		touch $*.test.build.stamp

%.test.o : %.test.c
	@$(CC) $(CFLAGS) $(COMMON_SEARCH_PATHS)\
		$<\
		$(COMMON_LIBS)\
		-o $@\
		$(GCC_LD_OPTS);
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
