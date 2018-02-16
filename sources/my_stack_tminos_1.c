#include "fillit.h"

static int	compare_stacks(t_stack_state *s)
{
	int		i;
	int		ret;

	i = -1;
	while (++i < MAX_STACK_HEIGHT * MAX_STACK_WIDTH)
		if ((ret = !!(char*)s->wk_grid[i]) != !!(char*)s->ret[i])
			return (!ret);
	return (1);
}

static void	compare_best(t_stack_state *s,
							t_stack_values *v)
{
	int		i;
	int		j;
	int		max;

	max = v->max_dim;
	i = -1;
	while (++i < s->best)
		max = v->row_ends[i] > max ? v->row_ends[i] : max;
	i = -1;
	while (++i < s->best)
		max = v->col_ends[i] > max ? v->col_ends[i] : max;
	if (max > s->best || (max == s->best && compare_stacks(s)))
		return ;
	s->best = max;
	i = -1;
	while (++i < MAX_STACK_HEIGHT && (j = -1))
		while (++j < MAX_STACK_WIDTH)
			if (s->wk_grid[i][j])
				s->ret[i][j] = s->wk_grid[i][j];
			else
				s->ret[i][j] = '.';
}

static void	here_stack(t_stack_state *, t_stack_values *);

static void setup_grid_n_maxs_n_vals(t_stack_state *state,
							t_stack_values *v,
							int	row, int col)
{
	int		i;
	int		j;
	char	(* const p_mino)[4] = v->mino->ar;
	char	(* const p_grid)[MAX_STACK_WIDTH] = state->wk_grid;

	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4)
			if ((p_grid[row + i][col + j] = p_mino[i][j]))
			{
				if (row + i > v->col_ends[col + j])
					v->col_ends[col + j] = row + i;
				if (col + j > v->row_ends[row + i])
					v->row_ends[row + i] = col + j;
			}
	v->mino = (v->mino + 1);
}

static int	try_tmino_pos(t_stack_state *state,
							t_stack_values v,
							int	row, int col)
{
	int		i;
	int		j;
	char	(* const p_mino)[4] = v.mino->ar;
	char	(* const p_grid)[MAX_STACK_WIDTH] = state->wk_grid;

	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4)
			if (p_mino[i][j] && p_grid[row + i][col + j])
				return (0);
	setup_grid_n_maxs_n_vals(state, &v, row, col);
	here_stack(state, &v);
	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4)
			if (p_mino[i][j])
				p_grid[row + i][col + j] = 0;
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
		while (++i <= state->best - v->mino->h + 1 &&
				((j = v->row_ends[i] - 1) || 1))
			while (++j <= state->best - v->mino->w + 1)
				if (try_tmino_pos(state, *v, i, j))
					break;
		i = -1;
		while (++i <= state->best - v->mino->w + 1 &&
				((j = v->col_ends[i] - 1) || 1))
			while (++j < state->best - v->mino->h + 1)
				if (try_tmino_pos(state, *v, j, i))
					break;
	}
}

char		(*my_stack_tminos_1(t_mino *tminos, int *sz))[MAX_STACK_WIDTH]
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
		state.best = MAX_STACK_HEIGHT;
		here_stack(&state,
					&((t_stack_values){
						.row_ends = {0},
						.col_ends = {0},
						.max_dim = 0,
						.mino = tminos
					})
		);
		*sz = state.best + 1;
	}
	return (state.ret);
}
