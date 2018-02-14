#include "fillit.h"

static void		copy_tmino_into_big(unsigned char (*big)[6],\
									unsigned char (*mino)[4])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 6 && (j = -1))
		while (++j < 6)
			if (i > 0 && i < 5 && j > 0 && j > 5)
				big[i][j] = mino[i - 1][j - 1];
			else
				big[i][j] = '\0';
}

static int		bad_last_tmino_shape(t_mino *ar, int i)
{
	unsigned char	big[6][6];
	unsigned char	(*p)[4];
	int				j;

	copy_tmino_into_big(big, ar[i].ar);
	p = (unsigned char (*)[4])&(big[1][1]);
	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4)
			if (p[i][j] && !(p[i - 1][j] || p[i + 1][j] ||
				p[i][j - 1] || p[i][j + 1]))
				return (1);
	return (0);
}

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
				bad_last_tmino_shape(ar, i))
				return (1);	
		}
		c = *input++;
	}
	ar[i].ar[0][0] = TMINO_STR_END;
	return (c);
}

#include <stdio.h>
static t_mino	*get_input(const char *input) __attribute__ ((unused));
static t_mino	*get_input(const char *input)
{
	int		fd;
	char	buff[BUFF_SZ] = {0};
	ssize_t	index;
	t_mino	*ret_ar;

	ret_ar = 0;
/*
	if ((fd = open(input, O_RDONLY) ^ -1) && (printf("yo") || 1) &&\
	(index = read(fd, buff, BUFF_SZ)) > 0 && (printf("yu") || 1) &&\
	index < BUFF_SZ && (printf("yc") || 1) &&\
	(ret_ar = malloc((TMINO_MAX_CT + 1) * sizeof(t_mino))))
*/
	printf("input is : %s\n", input);
	if ((fd = open(input, O_RDONLY) != -1))
	{
		printf("yo");
		if((index = read(fd, buff, BUFF_SZ)) > 0)
		{
			printf("yp");
			if (index < BUFF_SZ)
			{
				printf("yq");
				if ((ret_ar = malloc((TMINO_MAX_CT + 1) * sizeof(t_mino))))
				{
					printf("yr");
					if (set_ret_ar(ret_ar, buff))
					{
						free(ret_ar);
						ret_ar = 0;
						my_usage(USAGE_BAD_TETRAMINOS);
					}
				}
			}
		}
		else
			my_usage(USAGE_BAD_FILE);
	}
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
