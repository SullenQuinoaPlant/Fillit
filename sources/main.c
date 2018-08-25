#include "fillit.h"

int		main(int ac, char *av[])
{
	t_mino		tminos[TMINO_MAX_CT + 1];
	t_s_pos		positions[TMINO_MAX_CT + 1];
	int			side;

	side = 0;
	positions[TMINO_MAX_CT] = (t_s_pos){-1, -1};
	if ((check_input(ac, av, tminos)) &&
		(side = stack_tminos(tminos, positions)) &&
		print_stack(side, positions, tminos))
		return (1);
	return (0);
}
