#include "fillit.h"

static char	(*stack(t_mino *tminos))[MAX_STACK_WIDTH]
{
	
}

char	(*my_stack_tminos_1(t_mino *tminos))[MAX_STACK_WIDTH]
{
	char	(*ret)[MAX_STACK_WIDTH];
	int		row_ends[MAX_STACK_HEIGHT] = {0};
	int		col_ends[MAX_STACK_WIDTH] = {0};
	int		i;
	int		j;

	if ((ret = malloc(sizeof(t_stack_grid))))
	{
		i = -1;
		while (++i < MAX_STACK_HEIGHT && (j = -1))
			while (++j < MAX_STACK_WIDTH)
				ret[i][j] = '\0';

	}
	return (ret);
}
