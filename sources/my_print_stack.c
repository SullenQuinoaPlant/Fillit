#include "fillit.h"

static
void
	paste_minos(
		int side, t_s_pos *pos, t_mino *mino, char *out)
{
	int		i;
	int		j;
	char	c;

	while (mino->bits)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if ((c = mino->ar[i][j]))
					out[(pos->i + i) * (side + 1) + pos->j + j] = c;
		}
		mino++;
		pos++;
	}
}

int
	print_stack(
		int side, t_s_pos *pos, t_mino *minos)
{
	size_t	const sz = side * (side + 1) + 1;
	char	*out;
	int		i;

	if (!(out = malloc(sz)))
	{
		usage(USAGE_SYS_ERR);
		return (0);
	}
	ft_memset(out, '.', sz - 2);
	out[sz - 1] = 0;
	i = 0;
	while (i < side)
		out[++i * side] = '\n';
	paste_minos(side, pos + i, minos + i, out);
	ft_putstr(out);
	free(out);
	return (1);
}
