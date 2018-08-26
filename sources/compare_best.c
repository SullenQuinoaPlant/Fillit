#include "fillit.h"

static
void
	set_best(
		t_stack_state *s, int new_best)
{
	int		i;

	s->best = new_best;
	i = -1;
	while (++i < TMINO_MAX_CT)
		s->ret_pos[i] = s->wk_pos[i];
}

int
	compare_best(t_stack_state *s)
{
	int			i;
	int			j;
	uint16_t	prod;
	int			stop;

	i = s->best + 1;
	prod = 0x1 << i;
	stop = 1;
	while (--i > stop)
		if (s->wk_grid[i + 1])
			stop = i;
		else
		{
			prod >>= 1;
			j = -1;
			while (++j < i)
				if (s->wk_grid[j + 1] & prod)
					stop = i;
		}
	if (stop < s->best)
		set_best(s, stop);
	return (1);
}

