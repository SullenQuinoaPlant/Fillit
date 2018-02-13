DEPTH = ..
ifndef $(ROOT)
	include $(DEPTH)/make_vars.mk	
endif

D = $(ROOT)/auxilliary

HERE_OBJS := $(patsubst %.c, %.o, $(wildcard $D/*.c))


libaux.a : $(HERE_OBJS)
	echo $(HERE_OBJS)
	ar -rcs $(HERE_OBJS) -o 
	mv $@ $(LIB_DIR)
	cp auxilliaries.h $(LIB_H_DIR)

$D/%.o : $D/%.c
	$(CC) $(CFLAGS) $(CSEARCHES) -c $< -o $@
