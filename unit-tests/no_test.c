#define main testee_main
# include "FILE"
#undef main

int		main(int ac, char *av[])
{
	(void)ac;
	(void)av;

	return (0);
}
