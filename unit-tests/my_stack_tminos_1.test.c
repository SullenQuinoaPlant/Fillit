//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


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
		t_stack_grid ref = {
			{'A'},
			{'A'},
			{'A'},
			{'A'},
		}
		set_grid((int*)ref);
		aux_print_stack_grid(ref);
			
		assert_true(1);
	)

    return (
		_cmocka_run_group_tests(
					"TEST_ARR", TEST_ARR,
					test_index, 0, 0
		)
	);
}
