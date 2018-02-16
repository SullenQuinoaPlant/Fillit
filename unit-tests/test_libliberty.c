#include <liberty.h>

int		main()
{
	char*	*argv;

	argv = buildargv("hello fuck you");
	if (argv)
		freeargv(argv);
	return (0);
}
