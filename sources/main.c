#include "fillit.h"

int		main(int ac, char *av[])
{
	t_mino			*place_these;
	int				ret_sz;
	t_p_stack_grid	ret;

	ret_sz = 0;
	if ((place_these = my_check_input(ac, av)))
	{
		my_arrange_tminos_arr(place_these);
		if ((ret = my_stack_tminos_6(place_these, &ret_sz)))
		{
			my_print_stack(ret, ret_sz);
			free(ret);
		}
		if ((ret = my_stack_tminos_4(place_these, &ret_sz)))
		{
			my_print_stack(ret, ret_sz);
			free(ret);
		}
		if ((ret = my_stack_tminos_3(place_these, &ret_sz)))
		{
			my_print_stack(ret, ret_sz);
			free(ret);
		}
//		if ((ret = my_stack_tminos_2(place_these, &ret_sz)))
//		{
//			my_print_stack(ret, ret_sz);
//			free(ret);
//		}
		free(place_these);
	}
	return (!!ret_sz);
}
