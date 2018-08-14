#include "fillit.h"

void	my_print_stack(t_tsg_ptr grid, int side)
{
	int		i;
	int		j;

	i = -1;
	while (++i < side)
	{
		j = -1;
		while (++j < side)
			write(1, &grid[i][j], 1);
		write(1, "\n", 1);
	}
}
