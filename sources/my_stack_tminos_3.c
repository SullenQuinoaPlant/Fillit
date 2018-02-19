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
	char			c;
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
			s->ret[i][j] = (c = s->wk_grid[i][j]) ? c : '.';
	s->best = max;
}

static void	here_stack(t_stack_state *, t_mino *);

//static void setup_grid_n_maxs_n_vals(t_stack_state *state,
//							t_stack_values *v,
//							int	row, int col)
//{
//	int		i;
//	int		j;
//	char	(* const p_mino)[4] = v->mino->ar;
//	char	(* const p_grid)[MAX_STACK_WIDTH] = state->wk_grid;
//
//	i = -1;
//	while (++i < v->mino->h && (j = -1))
//		while (++j < v->mino->w)
//			p_grid[row + i][col + j] |= p_mino[i][j];
////			if ((p_grid[row + i][col + j] |= p_mino[i][j]))
////			{
////				if (row + i > v->col_ends[col + j])
////					v->col_ends[col + j] = row + i;
////				if (col + j > v->row_ends[row + i])
////					v->row_ends[row + i] = col + j;
////			}
//	v->mino = (v->mino + 1);
//}

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
	int		modi;
	int		modj;

	if (mino->ar[0][0] == TMINO_STR_END)
		compare_best(state);
	else
	{
		i = -1;
		while (++i < (modi = state->best - mino->h + 2) && (j = -1))
			while (++j < (modj = state->best - mino->w + 2))
				try_tmino_pos(state, mino, i, j);
//				try_tmino_pos(state, *v, i, (v->row_ends[i] + j) % modj);
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
			{
				state.ret[i][j] = '\0';
				state.wk_grid[i][j] = '\0';
			}
		state.best = WORST_BEST; 
		here_stack(&state, tminos);
		*sz = state.best + 1;
	}
	return (state.ret);
}
