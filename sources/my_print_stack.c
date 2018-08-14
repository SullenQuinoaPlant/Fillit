#include "fillit.h"

void	my_print_stack(t_tsg_ptr grid, int side)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < side)
	{
		j = -1;
		while (++j < side)
		{
			if (!(c = grid[i][j]))
				c = '.';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}
