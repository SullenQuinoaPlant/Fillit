#include "fillit.h"

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
	if (max == s->best)
		return ;
	i = -1;
	while (++i <= s->best && (j = -1))
		while (++j <= s->best)
			s->ret[i][j] = wk_grid[i][j];
	s->best = max;
}

static void	here_stack(t_stack_state *,
				int h, int w, t_mino *tmino);

static int	try_tmino_pos(t_stack_state *s,
							int	row, int col, t_mino* tmino)
{
	int		i;
	int		j;
	char	(* const p_mino)[4] = tmino->ar;
	char	(* const p_grid)[MAX_STACK_WIDTH] = s->wk_grid;

	i = -1;
	while (++i <= tmino->h && (j = -1))
		while (++j <= tmino->w)
			if (p_mino[i][j] && p_grid[row + i][col + j])
				return (0);
	i = -1;
	while (++i <= tmino->h && (j = -1))
		while (++j <= tmino->w)
			p_grid[row + i][col + j] |= p_mino[i][j];
	here_stack(s, (tmino + 1)->h, (tmino +1)->w, tmino + 1);
	i = -1;
	while (++i <= tmino->h && (j = -1))
		while (++j <= tmino->w)
			p_grid[row + i][col + j] &= ~p_mino[i][j];
	return (1);
}

static void	here_stack(t_stack_state *s,
				int h, int w, t_mino *tmino)
{
	int			i;
	int			j;
	int			best;

	i = -1;
	best = s->best;
	if (tmino->ar[0][0] == TMINO_STR_END)
		compare_best(s);
	else
		while (++i < s->best + 1)
		{
			j = -1;
			while (++j <= best &&
				i + h <= best &&
				j + w <= best)
			{
				try_tmino_pos(s, i, j, tmino);
				best = s->best;
			}
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
		here_stack(&state, tminos->h, tminos->w, tminos);
		*sz = state.best + 1;
	}
	return (state.ret);
}
