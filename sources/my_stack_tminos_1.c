#include "fillit.h"

static void	compare_best(t_stack_state state, int *row_ends, int *col_ends)
{
	int		i;
	int		j;
	int		max;

	max = 0;
	i = -1;
	while (++i < MAX_STACK_HEIGHT)
		max = row_ends[i] > max ? row_ends[i] : max;
	i = -1;
	while (++i < MAX_STACK_WIDTH)
		max = row_ends[i] > max ? col_ends[i] : max;
	if (max >= best)
		return ;
	i = -1;
	while (++i < MAX_STACK_HEIGHT && (j = -1))
		while (++j < MAX_STACK_WIDTH)
			ret[i][j] = state.wk_grid[i][j] ? state.wk_grid[i][j] : '.';
}

static void	here_stack(t_stack_state state, int *row_ends, int *col_ends, t_mino *tminos)
{
	if (!tminos)
		compare_best(state);
	else
	{
		;
	}
}

char		(*my_stack_tminos_1(t_mino *tminos))[MAX_STACK_WIDTH]
{
	t_stack_state	state;
	int				i;
	int				j;

	if ((state.ret = malloc(sizeof(t_stack_grid))))
	{
		i = -1;
		while (++i < MAX_STACK_HEIGHT && (j = -1))
			while (++j < MAX_STACK_WIDTH)
				state.wk_grid[i][j] = '\0';
		here_stack(state,
					((int[MAX_STACK_HEIGHT]){0}),
					((int[MAX_STACK_WIDTH){0}),
					tminos);
	}
	return (state.ret);
}
