#include "fillit.h"

static int		follow_tmino_shape(char (*ar)[4], int i, int j)
{
	int		k;
	int		ii;
	int		jj;
	int 	count;

	ar[i][j] = 0;
	count = 1;
	k = -1;
	while (++k < 4)
	{
		ii = i + ((k % 3) - 1) * ((k + 1) % 2);
		ii = ii >= 0 && ii < 4 ? ii : 0;
		jj = j + ((k - 2) * (k % 2));
		jj = jj >= 0 && jj < 4 ? jj : 0;
		if (ar[ii][jj])
			count += follow_tmino_shape(ar, ii, jj);
	}
	return (count);
}

static int		bad_tmino_shape(t_mino * mino)
{
	char	ar[4][4];
	int		i;
	int		j;

	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4)
			ar[i][j] = mino->ar[i][j];
	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4)
			if (ar[i][j])
				return (follow_tmino_shape(ar, i, j) - 4);
	return (0);
}

static
int
	set_ret_ar(
		const char *input, t_mino *ar)
{
	int		i;
	int		j;
	int		k;
	char	c;

	i = -1;
	c = '\n';
	while (++i < TMINO_MAX_CT && c == '\n'  && (j = -1))
	{
		while (++j < 4 && (k = -1))
		{
			while (++k < 4 && ((c = *input++) == '.' || c == '#'))
				ar[i].ar[j][k] = c == '.' ? 0 : 'A' + i;
			if (k < 4 || (c = *input++) ^ '\n')
				return (1);
		}
		if (bad_tmino_shape(ar + i))
			return (1);
		c = *input++;
	}
	ar[i].ar[0][0] = TMINO_STR_END;
	return (c);
}

static
t_mino *
	get_input(
		const char *input, tmino *ret_ar)
{
	int		fd;
	char	buff[BUFF_SZ] = {0};
	ssize_t	index;
	t_mino	*ret_ar;

	ret_ar = 0;
	if (((fd = open(input, O_RDONLY)) ^ -1) &&
		(index = read(fd, buff, BUFF_SZ)) > 0 &&
		index < BUFF_SZ)
	{
		if (set_ret_ar(buff, ret_ar))
			my_usage(USAGE_BAD_TETRAMINOS);
	}
	else
		my_usage(USAGE_BAD_FILE);
	close(fd);
	return (ret_ar);
}

t_mino
	*my_check_input(
		int ac, char *av[], t_mino *ret_ar)
{
	if (ac ^ 2)
		my_usage(USAGE_ARG_COUNT);
	else
		return (get_input(av[1], ret_ar));
	return (0);
}
