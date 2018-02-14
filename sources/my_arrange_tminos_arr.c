#include "fillit.h"

static int	up_shift(t_mino	mino)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3 && (j = -1))
		while (++j < 4)
			if (mino.ar[i][j])
				return (i);
	return (i);
}

static int	left_shift(t_mino mino, int up)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3 && ((j = up - 1) || 1))
		while (++j < 4)
			if (mino.ar[j][i])
				return (i);
	return (i);
}

void	my_arrange_tminos_arr(t_mino *arr)
{
	int		i;
	int		j;
	int		k;
	int		up;
	int		left;

	i = -1;
	while (arr[++i].ar[0][0] && (j = -1))
	{
		up = up_shift(arr[i]);
		left = left_shift(arr[i], up);
		while (++j < 4 && (k = -1))
			while (++k < 4)
				if (j + up < 4 && k + left < 4)
					arr[i].ar[j][k] = arr[i].ar[j + up][k + left];
				else
					arr[i].ar[j][k] = 0;
	}
}
