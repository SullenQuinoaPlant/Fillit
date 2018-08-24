#include "fillit.h"

int		main(int ac, char *av[])
{
	t_mino		tminos[TMINO_MAX_CT + 1];
	t_s_pos		positions[TMINO_MAX_CT];
	int			side;

	side = 0;
	if ((check_input(ac, av, tminos)))
	{
		arrange_tminos(tminos);
		if ((side = stack_tminos(place_these, positions)))
			print_stack(side, positions);
	}
	return (!!side);
}
