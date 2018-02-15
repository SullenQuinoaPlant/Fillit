//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


typedef struct	wrap_t_stac_grid {
	t_stack_grid	ar;
}				s_wrap_t_s_g;

void	set_grid(int *p)
{
	int		i;

	i = -1;
	while (++i < MAX_STACK_WIDTH * MAX_STACK_HEIGHT)
		if (p[i] == 0)
			p[i] = '.';
}

int		main(void)
{
	T(one_tmino,
		s_wrap_t_s_g ref = ((s_wrap_t_s_g){
			.ar = {
				{'A'},
				{'A'},
				{'A'},
				{'A'},
			}
		});
		set_grid((int*)ref.ar);
		aux_print_stack_grid(ref.ar);
			
		assert_true(1);
	)

    return (
		_cmocka_run_group_tests(
					"TEST_ARR", TEST_ARR,
					test_index, 0, 0
		)
	);
}
