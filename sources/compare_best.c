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

	i = s->best + 1;
	stop = 1;
	prod = 0x1 << s->best;
	while (--i)
	{
		if (s->wk_grid[i + 1])
			break;
		j = -1;
		while (++j < i)
			if (s->wk_grid[j + 1] & prod)
				break;
		prod >>= 1;
	}
	if (stop < s->best)
		set_best(s, stop);
	return (1);
}
