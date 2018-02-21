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

static void	compare_best(t_stack_state *s)
{
	int				i;
	int				j;
	int				max;
	t_p_stack_grid	wk_grid;

	wk_grid = s->wk_grid;
	max = 0;
	i = s->best + 1;
	while (!max && (i-- > 0) && (j = -1))
		while (j++ < i)
			if (wk_grid[i][j] || wk_grid[j][i])
				max = i;
	if (max == s->best && compare_stacks(s))
		return ;
	i = -1;
	while (++i <= s->best && (j = -1))
		while (++j <= s->best)
			s->ret[i][j] = wk_grid[i][j];
	s->best = max;
}

static void	here_stack(t_stack_state *, t_mino *);

static int	try_tmino_pos(t_stack_state *state,
							t_mino *mino,
							int	row, int col)
{
	int		i;
	int		j;
	char	(* const p_mino)[4] = mino->ar;
	char	(* const p_grid)[MAX_STACK_WIDTH] = state->wk_grid;

	i = -1;
	while (++i < mino->h && (j = -1))
		while (++j < mino->w)
			if (p_mino[i][j] && p_grid[row + i][col + j])
				return (0);
	i = -1;
	while (++i < mino->h && (j = -1))
		while (++j < mino->w)
			p_grid[row + i][col + j] |= p_mino[i][j];
	mino += 1;
	here_stack(state, mino);
	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4 - i)
			if (p_mino[i][j])
				p_grid[row + i][col + j] = 0;
	return (1);
}

static void	here_stack(t_stack_state *state, t_mino *mino)
{
	int			i;
	int			j;
	static int	tick;
	int			* const p1 = tick ? &i : &j;
	int			* const p2 = tick ? &j : &i;

	if (mino->ar[0][0] == TMINO_STR_END)
		compare_best(state);
	else
	{
		tick = ~tick;
		i = -1;
		while (++i < state->best + 1)
		{
			j = -1;
			while (j++ && i <= state->best)
				try_tmino_pos(state, mino, *p1, *p2);
			j = -1;
			while (++j < i && i <= state->best)
				try_tmino_pos(state, mino, *p2, *p1);
		}
	}
}

char		(*my_stack_tminos_5(t_mino *tminos, int *sz))[MAX_STACK_WIDTH]
{
	t_stack_state	state;
	int				i;
	int				j;
	char			c;

	if ((state.ret = malloc(sizeof(t_stack_grid))))
	{
		i = -1;
		while (++i < MAX_STACK_HEIGHT && (j = -1))
			while (++j < MAX_STACK_WIDTH)
			{
				c = i <= WORST_BEST && j <= WORST_BEST ? '\0' : 1;
				state.ret[i][j] = c;
				state.wk_grid[i][j] = c;
			}
		state.best = WORST_BEST; 
		here_stack(&state, tminos);
		i = -1;
		while (++i <= state.best && (j = -1))
			while (++j <= state.best)
				state.ret[i][j] = (c = state.ret[i][j]) ? c : '.';
		*sz = state.best + 1;
	}
	return (state.ret);
}
