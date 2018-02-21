#include "fillit.h"

static int	compare_stacks(t_stack_state *s)
{
	int		i;
	int		j;
	int		ret;

	i = -1;
	while (++i <= s->best && (j = -1))
		while (++j <= s->best)
			if ((ret = !!s->wk_grid[i][j]) != !!s->ret[i][j])
				return (!ret);
	return (1);
}

static void	compare_best(t_stack_state *s,
							t_stack_values *v)
{
	int		i;
	int		j;
	int		max;

	max = 0;
	i = -1;
	while (++i < s->best)
		max = v->row_ends[i] > max ? v->row_ends[i] : max;
	i = -1;
	while (++i < s->best)
		max = v->col_ends[i] > max ? v->col_ends[i] : max;
	if (max == s->best && compare_stacks(s))
		return ;
	i = -1;
	while (++i <= s->best && (j = -1))
		while (++j <= s->best)
			s->ret[i][j] = s->wk_grid[i][j];
	s->best = max;
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
	while (++i < v->mino->h && (j = -1))
		while (++j < v->mino->w)
			if ((p_grid[row + i][col + j] |= p_mino[i][j]))
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
	while (++i < v.mino->h && (j = -1))
		while (++j < v.mino->w)
			if (p_mino[i][j] && p_grid[row + i][col + j])
				return (0);
	setup_grid_n_maxs_n_vals(state, &v, row, col);
	here_stack(state, &v);
	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4 - i)
			if (p_mino[i][j])
				p_grid[row + i][col + j] = 0;
	return (1);
}

static void	here_stack(t_stack_state *state,
						t_stack_values *v)
{
	int		i;
	int		j;
	int		modi;
	int		modj;

	if (v->mino->ar[0][0] == TMINO_STR_END)
		compare_best(state, v);
	else
	{
		i = -1;
		while (++i < (modi = state->best - v->mino->h + 2) && (j = -1))
			while (++j < (modj = state->best - v->mino->w + 2))
//				try_tmino_pos(state, *v, i, j);
				try_tmino_pos(state, *v, i, (v->row_ends[i] + j) % modj);
	}
}

char		(*my_stack_tminos_2(t_mino *tminos, int *sz))[MAX_STACK_WIDTH]
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
		state.best = WORST_BEST; 
		here_stack(&state,
					&((t_stack_values){
						.row_ends = {0},
						.col_ends = {0},
						.mino = tminos
					})
		);
		i = -1;
		while (++i < state.best && (j = -1))
			while (++j < state.best)
				if (!state.ret[i][j])
					state.ret[i][j] = '.';
		*sz = state.best + 1;
	}
	return (state.ret);
}
