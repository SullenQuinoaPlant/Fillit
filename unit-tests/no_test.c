#ifdef main
# undef main
#endif

#include <stdio.h>

int		main(int ac, char *av[])
{
	(void)ac;
	(void)av;

	testee_main(0, 0);
	printf("no_test.c\n");
	return (0);
}
