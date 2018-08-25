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

static void	shift_tmino(t_mino *mino)
{
	int		j;
	int		k;
	int		up;
	int		left;

	up = up_shift(*mino);
	left = left_shift(*mino, up);
	j = -1;
	while (++j < 4 && (k = -1))
		while (++k < 4)
			if (j + up < 4 && k + left < 4)
				mino->ar[j][k] = mino->ar[j + up][k + left];
			else
				mino->ar[j][k] = 0;
}

static void	set_w_h(t_mino *mino)
{
	int		i;
	int		j;
	int		clear;

	i = 4;
	clear = 1;
	while (clear && --i > 0 && (j = -1))
		while (clear && ++j < 4)
			if (mino->ar[i][j])
				clear = 0;
	mino->h = i;
	j = 4;
	clear = 1;
	while (clear && --j > 0 && (i = -1))
		while (clear && i++ < mino->h)
			if (mino->ar[i][j])
				clear = 0;
	mino->w = j;
}

void
	arrange_tmino(
		t_mino *mino)
{
	shift_tmino(mino);
	set_w_h(mino);
}
