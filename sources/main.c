#include "fillit.h"

int		main(int ac, char *av[])
{
	t_mino			*place_these;
	int				ret_sz;
	t_p_stack_grid	ret;

	ret_sz = 0;
	if ((place_these = my_check_input(ac, av)))
	{
		my_arrange_tminos_arr_1(place_these);
//		if ((ret = my_stack_tminos_6_1(place_these, &ret_sz)))
//		{
//			my_print_stack(ret, ret_sz);
//			ft_putchar('\n');
//			free(ret);
//		}
		if ((ret = my_stack_tminos_7(place_these, &ret_sz)))
		{
			my_print_stack(ret, ret_sz);
			ft_putchar('\n');
			free(ret);
		}
		free(place_these);
	}

//	if ((place_these = my_check_input(ac, av)))
//	{
//		my_arrange_tminos_arr(place_these);
//		if ((ret = my_stack_tminos_6(place_these, &ret_sz)))
//		{
//			my_print_stack(ret, ret_sz);
//			ft_putchar('\n');
//			free(ret);
//		}
//		if ((ret = my_stack_tminos_5(place_these, &ret_sz)))
//		{
//			my_print_stack(ret, ret_sz);
//			ft_putchar('\n');
//			free(ret);
//		}
//		if ((ret = my_stack_tminos_4(place_these, &ret_sz)))
//		{
//			my_print_stack(ret, ret_sz);
//			ft_putchar('\n');
//			free(ret);
//		}
		free(place_these);
	}
	return (!!ret_sz);
}
