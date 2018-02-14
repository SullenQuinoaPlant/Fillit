DEPTH = ..
ifndef ROOT
	include $(DEPTH)/Make_vars.mk	
endif

D = $(ROOT)/auxilliary

HERE_OBJS := $(patsubst %.c, %.o, $(wildcard $(D)/*.c))
HERE_OBJS := $(wildcard ./auxilliary/*.c)
HERE_OBJS := $(D)/*.o


libaux.a : $(HERE_OBJS)
	echo $(HERE_OBJS)
	ar -rcs $@ $(HERE_OBJS)
	mv $@ $(LIB_DIR)
	cp auxilliaries.h $(LIB_H_DIR)

$D/%.o : $D/%.c
	$(CC) $(CFLAGS) $(CSEARCHES) -c $< -o $@
