#include "fillit.h"

static int	better_grid(t_stack_state *s)
{
	int		const best = s->best;
	int		i;
	int		j;
	int		r;

	i = -1;
	while (++i < best)
	{
		j = -1;
		while (++j < best)
		{
			r = !s->wk_grid[i][j];
			if (r != !s->ret[i][j])
				return (!r);
		}
	}
	return (0);
}

static void	compare_best(t_stack_state *s)
{
	int				i;
	int				j;
	int				max;
	t_tsg_ptr	wk_grid;

	wk_grid = s->wk_grid;
	max = 0;
	i = s->best + 1;
	while (!max && (i-- > 0) && (j = -1))
		while (j++ < i)
			if (wk_grid[i][j] || wk_grid[j][i])
				max = i;
	if (max == s->best && !better_grid(s))
		return ;
	i = -1;
	while (++i <= s->best && (j = -1))
		while (++j <= s->best)
			s->ret[i][j] = wk_grid[i][j];
	s->best = max;
}

static void	here_stack(t_stack_state *, t_mino *, int tick);

static int	try_tmino_pos(t_stack_state *state,
							t_mino *mino,
							int	row, int col)
{
	int		i;
	int		j;
	char	(* const p_mino)[4] = mino->ar;
	char	(* const p_grid)[MAX_STACK_WIDTH] = state->wk_grid;

	i = -1;
	while (++i <= mino->h && (j = -1))
		while (++j <= mino->w)
			if (p_mino[i][j] && p_grid[row + i][col + j])
				return (0);
	i = -1;
	while (++i <= mino->h && (j = -1))
		while (++j <= mino->w)
			p_grid[row + i][col + j] |= p_mino[i][j];
	here_stack(state, mino + 1, (col & 1) != (col & 1));
	i = -1;
	while (++i <= mino->h && (j = -1))
		while (++j <= mino->w)
			p_grid[row + i][col + j] &= ~p_mino[i][j];
	return (1);
}

static void	here_stack(t_stack_state *s, t_mino *m, int tick)
{
	int			i;
	int			j;
	int			* const p1 = tick ? &i : &j;
	int			* const p2 = tick ? &j : &i;

	if (m->ar[0][0] == TMINO_STR_END)
		compare_best(s);
	else
	{
		i = -1;
		while (++i < s->best + 1)
		{
			j = -1;
			while (++j <= i && *p1 + m->h <= s->best && *p2 + m->w <= s->best)
				try_tmino_pos(s, m, *p1, *p2);
			j = -1;
			while (++j < i && *p2 + m->h <= s->best && *p1 + m->w <= s->best)
				try_tmino_pos(s, m, *p2, *p1);
		}
		tick = ~tick;
	}
}

t_tsg_ptr	my_stack_tminos(t_mino *tminos, int *sz)
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
				c = i <= WORST_BEST && j <= WORST_BEST ? '\0' : 0x80;
				state.ret[i][j] = c;
				state.wk_grid[i][j] = c;
			}
		state.best = WORST_BEST; 
		here_stack(&state, tminos, 0);
		*sz = state.best + 1;
	}
	return (state.ret);
}
