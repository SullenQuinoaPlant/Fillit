ifndef ROOT
	ROOT = ..
	include $(ROOT)/Make_vars.mk	
endif

D = $(ROOT)/auxilliary

HERE_OBJS := $(patsubst %.c, %.o, $(wildcard $(D)/*.c))


libaux.a : $(HERE_OBJS)
	echo $(HERE_OBJS)
	ar -rcs $@ $(HERE_OBJS)
	mv $@ $(LIB_OBJ_DIR)
	cp $(D)/auxilliaries.h $(LIB_H_DIR)

$D/%.o : $D/%.c
	$(CC) $(CFLAGS) -I $(LIB_H_DIR) -c $< -o $@
