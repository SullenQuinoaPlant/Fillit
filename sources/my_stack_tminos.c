#include "fillit.h"

static
int
	compare_best(t_stack_state *s)
{
	int			i;
	int			j;
	uint16_t	prod;
	int			stop;

	i = s->best;
	stop = 1;
	while (--i > stop && !s->wk_grid[i + 1])
	{
		prod = 0x1 << i;
		j = -1;
		while (j++ < i)
			if (s->wk_grid[j + 1] & prod)
				stop = i;
	}
	s->best = i;
	j = -1;
	while (++j < TMINO_MAX_CT)
		s->ret_pos[j] = s->wk_pos[j];
	return (1);
}

static
void
	set_grid(
		uint64_t set, uint16_t *here)
{
	uint16_t	chk;
	int			i;

	i = -1;
	while (++i < 4)
	{
		chk = (uint16_t)set;
		set >>= 16;
		*here++ |= chk;
	}
}

static
void
	unset_grid(
		uint64_t unset, uint16_t *here)
{
	uint16_t	chk;
	int			i;

	unset = ~unset;
	i = -1;
	while (++i < 4)
	{
		chk = (uint16_t)unset;
		unset >>= 16;
		*here++ &= chk;
	}
}

static
void
	recurse(
		t_stack_state *s,
		int h, int w, int rk)
{
	int			i;
	int			j;
	uint64_t	mino_bits;
	uint64_t	grid;

	if (!(mino_bits = s->tminos[rk].bits) && compare_best(s))
		return;
	ft_memcpy(&grid, s->wk_grid, sizeof(uint64_t));
	i = -1;
	while (++i + h < s->best)
	{
		grid = (grid >> 16) | ((uint64_t)s->wk_grid[i + 3] << 48);
		j = -1;
		while (++j + w < s->best && i + h < s->best)
		{
			if (!(mino_bits & grid))
			{
				s->wk_pos[rk] = (t_s_pos){i, j};
				set_grid(mino_bits, s->wk_grid + i + 1);
				recurse(s, s->tminos[rk + 1].h, s->tminos[rk + 1].w, rk + 1);
				unset_grid(mino_bits, s->wk_grid + i + 1);
			}
			mino_bits <<= 1;
		}
		mino_bits = s->tminos[rk].bits;
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
		state.wk_pos[i] = (t_s_pos){-1, -1};
	recurse(&state, tminos->h, tminos->w, 0);
	return (state.best + 1);
}
