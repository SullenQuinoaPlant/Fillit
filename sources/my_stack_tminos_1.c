#include "fillit.h"

static void	compare_best(t_stack_state *state,
							t_stack_values *v)
{
	int		i;
	int		j;
	int		max;

	max = v->max_dim;
	i = -1;
	/*shouldn't have to search beyond state-> max.
	 * leaving things as are, to help hunt bugs
	 */
	while (++i < MAX_STACK_HEIGHT)
		max = v->row_ends[i] > max ? v->row_ends[i] : max;
	i = -1;
	while (++i < MAX_STACK_WIDTH)
		max = v->col_ends[i] > max ? v->col_ends[i] : max;
	if (max >= state->best)
		return ;
	i = -1;
	while (++i < MAX_STACK_HEIGHT && (j = -1))
		while (++j < MAX_STACK_WIDTH)
			if (state->wk_grid[i][j])
				state->ret[i][j] = state->wk_grid[i][j];
			else
				state->ret[i][j] = '.';
}

static void	here_stack(t_stack_state *, t_stack_values *);

static int	try_tmino_pos(t_stack_state *state,
							t_stack_values v,
							int	row, int col)
{
	int			i;
	int			j;
	const char	(*p_mino)[4] = v.mino->ar;
	char		(*p_grid)[MAX_STACK_WIDTH] = state->wk_grid;

	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4)
			if (p_mino[i][j] && p_grid[row + i][col + j])
				return (0);
	i = -1;
	while (++i < 4 && (j = -1))
	{
		while (++j < 4)
		{
			p_grid[row + i][col + j] = p_mino[i][j];
			if (row + i > v.col_ends[col + j])
				v.col_ends[col + j] = row + i;
		}
		if (col + j - 1 > v.row_ends[row + i])
			v.row_ends[row + i] = col + j;
	}
	v.mino = (v.mino + 1);
	here_stack(state, &v);
	return (1);
}

static void	here_stack(t_stack_state *state,
						t_stack_values *v)
{
	int		i;
	int		j;

	if (v->mino->ar[0][0] == TMINO_STR_END)
		compare_best(state, v);
	else
	{
		i = -1;
		while (++i <= state->best - v->mino->h &&
				((j = v->row_ends[i]) || 1))
			while (++j <= state->best - v->mino->w)
				if (try_tmino_pos(state, *v, i, j))
					break;
		i = -1;
		while (++i <= state->best - v->mino->w &&
				((j = v->col_ends[i]) || 1))
			while (++j < state->best - v->mino->h)
				if (try_tmino_pos(state, *v, j, i))
					break;
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
		state.best = MAX_STACK_HEIGHT - 1;
		here_stack(&state,
					&((t_stack_values){
						((int[MAX_STACK_HEIGHT + 1]){0}),
						((int[MAX_STACK_WIDTH + 1]){0}),
						MAX_STACK_HEIGHT,
						tminos
					})
		);
	}
	return (state.ret);
}
