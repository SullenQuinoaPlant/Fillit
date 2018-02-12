#include "fillit.h"

/*BUFF_SZ is 26 * 4 * 5 + 25(empty lines) + 1 (file too long)*/
#define BUFF_SZ 546


static int		set_ret_ar(t_mino *ar, const char *input)
{
	int		i;
	int		j;
	int		k;
	char	c;

	i = -1;
	c = '\n';
	while (++i < 26 && c == '\n')
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4 && ((c = *input++) == '.' || c == '#'))
				ar[i].ar[j][k] = c == '.' ? c : 'A' + i;
			if (k < 4 || (c = *input++) ^ '\n')
				return (1);	
		}
		c = *input++;
	}
	return (c);
}

static t_mino	*get_input(const char *input)
{
	int		fd;
	char	buff[BUFF_SZ] = {0};
	ssize_t	index;
	t_mino	*ret_ar;

	ret_ar = 0;
	if ((fd = open(input, O_RDONLY) ^ -1))
	{
		if((index = read(fd, buff, BUFF_SZ)) > 0 && index < BUFF_SZ)
		{
			if ((ret_ar = malloc(26 * sizeof(t_mino))))
			{
				if (set_ret_ar(ret_ar, buff))
				{
					free(ret_ar);
					ret_ar = 0;
					my_usage(USAGE_BAD_TETRAMINOS);
				}
			}
		}
		close(index);
	}
	else
		my_usage(USAGE_BAD_FILENAME);
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
