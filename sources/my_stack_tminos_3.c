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

	max = 0;
	i = -1;
	while (++i < MAX_STACK_WIDTH)
		max = v->row_ends[i] ? i : max;
	if (max > s->best || (max == s->best && compare_stacks(s)))
		return ;
	i = -1;
	while (++i <= s->best && (j = -1))
		while (++j < s->best)
			if (s->wk_grid[i][j])
				s->ret[i][j] = s->wk_grid[i][j];
			else
				s->ret[i][j] = '.';
	s->best = max;
}

static void	here_stack(t_stack_state *, t_stack_values *);

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
		while (++j < 4 - i)
			if (p_mino[i][j] && p_grid[row + i][col + j])
				return (0);
	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4 - i)
			if ((p_grid[row + i][col + j] |= p_mino[i][j]))
			{
				v.row_ends[row + i]++;
				v.row_ends[col + j]++;
			}
	v.mino = v.mino + 1;
	here_stack(state, &v);
	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4 - i)
			p_grid[row + i][col + j] &= ~(p_mino[i][j]);
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
		modi = state->best - v->mino->h + 2;
		modj = state->best - v->mino->w + 2;
		i = -1;
		while (++i < modi && (j = -1))
			while (++j < modj)
				try_tmino_pos(state, *v, i, j);
	}
}

char		(*my_stack_tminos_3(t_mino *tminos, int *sz))[MAX_STACK_WIDTH]
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
						.row_ends = {0},
						.col_ends = {0},
						.mino = tminos
					})
		);
		*sz = state.best + 1;
	}
	return (state.ret);
}
