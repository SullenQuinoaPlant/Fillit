#include "h.h"

/*BUFF_SZ is 26 * 4 * 5 + 25(empty lines) + 1 (file too long)*/
#define BUFF_SZ 546

int		set_ret_ar(t_mino *ar, const char *input)
{
	(void)ar;
	(void)input;
	return (0);
}

t_mino	*get_input(const char *input)
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
					usage(USAGE_BAD_TETRAMINOS);
				}
			}
		}
		close(index);
	}
	else
		usage(USAGE_BAD_FILENAME);
	return (ret_ar);
}

t_mino	*check_input(int ac, char *av[])
{
	if (ac ^ 2)
		usage(USAGE_ARG_COUNT);
	else
		return (get_input(av[1]));
	return (0);
}
