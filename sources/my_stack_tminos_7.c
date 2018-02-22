#include "fillit.h"

static int	compare_stacks(t_stack_state *s)
{
	int		i;
	int		j;
	int		ret;

	i = -1;
	while (++i <= s->best && (j = -1))
		while (++j <= s->best)
			if ((ret = !s->wk_grid[i][j]) != !s->ret[i][j])
				return (ret);
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
	while (++i <= mino->h && (j = -1))
		while (++j <= mino->w)
			if (p_mino[i][j] && p_grid[row + i][col + j])
				return (0);
	i = -1;
	while (++i <= mino->h && (j = -1))
		while (++j <= mino->w)
			p_grid[row + i][col + j] |= p_mino[i][j];
	here_stack(state, mino + 1);
	i = -1;
	while (++i <= mino->h && (j = -1))
		while (++j <= mino->w)
			p_grid[row + i][col + j] &= ~p_mino[i][j];
	return (1);
}

static void	here_stack(t_stack_state *s, t_mino *m)
{
	static int	tick;
	int			i;
	int			ii;
	int			j __attribute__ ((unused));
	int			jj;
	int	* const *pt = tick % 2 ? (int*[2]){&ii, &jj} : (int*[2]){&jj, &ii};

	if (m->ar[0][0] == TMINO_STR_END)
		return (compare_best(s));
	else
	{
		i = -1;
		ii = (++tick / 2);
		while (++i <= WORST_BEST)
		{
			ii++;
			ii %= (WORST_BEST + 1);
			jj = -1;
			while (++jj <= ii)
				if (*pt[0] + m->h <= s->best &&
					*pt[1] + m->w <= s->best)
					try_tmino_pos(s, m, *pt[0], *pt[1]);
			jj = -1;
			while (++jj < ii)
				if (*pt[1] + m->h <= s->best &&
					*pt[0] + m->w <= s->best)
					try_tmino_pos(s, m, *pt[1], *pt[0]);
		}
	}
}

char		(*my_stack_tminos_7(t_mino *tminos, int *sz))[MAX_STACK_WIDTH]
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
				c = i <= WORST_BEST && j <= WORST_BEST ? '\0' : INVALID_POS;
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
