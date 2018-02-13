D = ./auxilliary

HERE_OBJS := $(patsubst %.c, %.o, $(wildcard $D/*.c))

libaux.a : $(HERE_OBJS)
	ar -rcs $(HERE_OBJS) -o 
	mv

$D/%.o : $D/%.c
	$(CC) $(CFLAGS) $< -o $@
