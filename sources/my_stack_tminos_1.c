#include "fillit.h"

char	(*my_stack_tminos_1(t_mino *tminos))[MAX_STACK_WIDTH]
{
	char	(*ret)[MAX_STACK_WIDTH];

	if ((ret = malloc(sizeof(t_stack_grid))))
	{
		(void)tminos;
	}
	return (ret);
}
