#include "fillit.h"

int		main(int ac, char *av[])
{
	t_mino		place_these[TMINO_MAX_CT + 1];
	t_mino		*place_these;
	int			ret_sz;
	t_tsg_ptr	ret;

	ret_sz = 0;
	if ((my_check_input(ac, av, place_these)))
	{
		my_arrange_tminos_arr(place_these);
		if ((ret = my_stack_tminos(place_these, &ret_sz)))
		{
			my_print_stack(ret, ret_sz);
			ft_putchar('\n');
			free(ret);
		}
		free(place_these);
	}
	return (!!ret_sz);
}
