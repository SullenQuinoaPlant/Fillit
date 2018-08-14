#include "fillit.h"

static int	not_better_stack(t_stack_state *s)
{
	int		i;
	int		j;
	int		k;
	int		ret;

	i = s->best + 1;
	k = -1;
	while (i--)
	{
		k++;
		j = -1;
		while (++j <= k)
		{
			ret = !s->wk_grid[i - j][j];
			if (ret != !s->ret[i - j][j])
				return (ret);
		}
	}
	return (1);
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
	if (max == s->best && not_better_stack(s))
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
	int			j;
	int			* const p1 = tick % 2 ? &i : &j;
	int			* const p2 = p1 == &i ? &j : &i;

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

char		(*my_stack_tminos(t_mino *tminos, int *sz))[MAX_STACK_WIDTH]
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
		here_stack(&state, tminos);
		i = -1;
		while (++i <= MAX_STACK_HEIGHT * MAX_STACK_WIDTH)
			((char*)state.ret)[i] = (c = ((char*)state.ret)[i]) ? c : '.';
		*sz = state.best + 1;
	}
	return (state.ret);
}
