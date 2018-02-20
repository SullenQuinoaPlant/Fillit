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
	char			c __attribute__ ((unused));
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
//			s->ret[i][j] = (c = s->wk_grid[i][j]) ? c : '.';
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
			p_grid[row + i][col + j] &= ~p_mino[i][j];
	return (1);
}

static void	here_stack(t_stack_state *state, t_mino *mino)
{
	int		i;
	int		j;
//	int		modi;
//	int		modj;

	if (mino->ar[0][0] == TMINO_STR_END)
		compare_best(state);
	else
	{
		i = -1;
		while (++i < state->best + 1)
		{
			if (i + mino->w - 1 <= state->best)
			{
				j = -1;
				while (i + mino->h - 1 - (j + 1) > state->best)
					j++;
				while (++j <= i)
					try_tmino_pos(state, mino, i - j, i);
			}
			if (i + mino->h - 1 < state->best + 1)
			{
				j = 0;
				while (i + mino->w - 1 - (j + 1) > state->best)
					j++;
				while (++j <= i)
					try_tmino_pos(state, mino, i, i - j);
			}
		}
	}
}

char		(*my_stack_tminos_4(t_mino *tminos, int *sz))[MAX_STACK_WIDTH]
{
	t_stack_state	state;
	int				i;
	int				j;
	char			*p_c;

	if ((state.ret = malloc(sizeof(t_stack_grid))))
	{
		i = -1;
		while (++i < MAX_STACK_HEIGHT && (j = -1))
			while (++j < MAX_STACK_WIDTH)
			{
				state.ret[i][j] = '\0';
				state.wk_grid[i][j] = '\0';
			}
		state.best = WORST_BEST; 
		here_stack(&state, tminos);
		i = -1;
		while (++i <= state.best && (j = -1))
			while (++j <= state.best)
				*(p_c = &state.ret[i][j]) ? (1) : (*p_c = '.');
		*sz = state.best + 1;
	}
	return (state.ret);
}
