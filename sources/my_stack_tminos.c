#include "fillit.h"

static void	compare_best(t_stack_state *s)
{
	int			i;
	int			j;
	uint16_t	prod;
	int			stop;

	i = s->best;
	prod = 0x1 << (i - 1);
	stop = 2;
	while (i > stop && !s->wk_grid[i])
	{
		j = -1;
		while (++j <= i)
			if (s->wk_grid[j] & prod)
				stop = i;
	}
	if (stop < s->best)
	{
		s->best = stop;
		j = -1;
		while (++j < TMINO_MAX_CT)
			s->ret_pos[j] = s->wk_pos[j];
	}
}

static
void
	recurse(
		t_stack_state *s,
		int h, int w, int r)
{
	int			i;
	int			j;
	uint64_t	mino_bits;
	uint64_t	grid_piece;

	ft_memcpy(&grid_piece, s->wk_grid, sizeof(uint64_t));
	i = -1;
	if (!(mino_bits = s->tminos[r++].bits))
		compare_best(s);
	else
		while (++i + h <= s->best)
		{
			grid_piece = (grid_piece >> 16) | s->wk_grid[i + 3];
			j = -1;
			while (++j + w <= s->best)
				if (!(mino_bits & grid_piece))
				{
					s->wk_pos[r - 1] = (t_s_pos){i, j};
					recurse(s, s->tminos[r].h, s->tminos[r].w, r);
				}
			mino_bits <<= 1;
		}
}

int
	stack_tminos(
		t_mino *tminos, t_s_pos *ret)
{
	t_stack_state	state;
	int				i;

	state.tminos = tminos;
	ft_memset((void*)state.wk_grid, 0, sizeof(t_stack_grid));
	state.best = WORST_BEST; 
	state.ret_pos = ret;
	i = -1;
	while (++i < TMINO_MAX_CT)
	{
		state.ret_pos[i] = (t_s_pos){-1, -1};
		state.wk_pos[i] = (t_s_pos){-1, -1};
	}
	recurse(&state, tminos->h, tminos->w, 0);
	return (state.best + 1);
}
