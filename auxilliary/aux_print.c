#include "fillit.h"
#include <stdio.h>

void	aux_print_2d_int_arr(int *arr, int d1, int d2)
{
	int		i;
	int		j;

	i = -1;
	while (++i < d1 && (j = -1))
	{
		while (++j < d2)
			printf("\t%d", arr[i * d2 + j]);
		printf("\n");
	}
}

void	aux_print_tmino(t_mino print_this)
	aux_print_2d_int_arr((int*)t_mino.ar, 4, 4);
