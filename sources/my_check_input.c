#include "fillit.h"

static int		copy_tmino_into_big_also_count(char (*big)[6],
									const char (*mino)[4])
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < 6 && (j = -1))
		while (++j < 6)
			if (!(i && j && i - 5 && j - 5))
				big[i][j] = 0;
			else
				count += (big[i][j] = mino[i - 1][j - 1]);
	return (count);
}

static int		bad_tmino_shape(t_mino *mino)
{
	char		big[6][6];
	const char	(*p)[4];
	int			i;
	int			j;

	p = (const char (*)[4])mino->ar;
	if ((i = copy_tmino_into_big_also_count(big, p)) != 4)
		return (1);
	i = 0;
	while (++i < 5 && (j = 0))
		while (++j < 5)
			if (big[i][j] && !(big[i - 1][j] || big[i + 1][j] ||
				big[i][j - 1] || big[i][j + 1]))
				return (1);
	return (0);
}

#include <stdio.h>
static int		set_ret_ar(t_mino *ar, const char *input)
{
	int		i;
	int		j;
	int		k;
	char	c;

	i = -1;
	c = '\n';
	while (++i < TMINO_MAX_CT && c == '\n')
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4 && ((c = *input++) == '.' || c == '#'))
				ar[i].ar[j][k] = c == '.' ? 0 : 'A' + i;
			if (k < 4 || (c = *input++) ^ '\n' ||
				bad_tmino_shape(ar + i))
			{
				if (bad_tmino_shape(ar + i))
				{
					printf("yo auie yo \n AUEAUIEAUIEAUIEAUIEAUIE\n");
					return (1);
				}
				else
				{
					return (1);
				}
			}
		}
		c = *input++;
	}
	ar[i].ar[0][0] = TMINO_STR_END;
	return (c);
}

static t_mino	*get_input(const char *input)
{
	int		fd;
	char	buff[BUFF_SZ] = {0};
	ssize_t	index;
	t_mino	*ret_ar;

	ret_ar = 0;
	if (((fd = open(input, O_RDONLY)) ^ -1) &&
		(index = read(fd, buff, BUFF_SZ)) > 0 &&
		index < BUFF_SZ &&
		(ret_ar = malloc((TMINO_MAX_CT + 1) * sizeof(t_mino))))
	{
		if (set_ret_ar(ret_ar, buff))
		{
			free(ret_ar);
			ret_ar = 0;
			my_usage(USAGE_BAD_TETRAMINOS);
		}
	}
	else
		my_usage(USAGE_BAD_FILE);
	close(fd);
	return (ret_ar);
}

t_mino			*my_check_input(int ac, char *av[])
{
	if (ac ^ 2)
		my_usage(USAGE_ARG_COUNT);
	else
		return (get_input(av[1]));
	return (0);
}
