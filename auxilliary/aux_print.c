#include "fillit.h"
#include <stdio.h>

void	aux_print_2d_char_arr(char *arr, int d1, int d2)
{
	int		i;
	int		j;

	i = -1;
	while (++i < d1 && (j = -1))
	{
		while (++j < d2)
			printf("\t.%c", arr[i * d2 + j]);
		printf("\n");
	}
}

void	aux_print_tmino(t_mino print_this)
{
	aux_print_2d_char_arr((char*)print_this.ar, 4, 4);
}

void	aux_print_tmino_string(t_mino *str)
{
	while ((*str).ar[0][0])
		aux_print_tmino(*str++);
}
