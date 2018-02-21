//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"

#include "auxilliaries.h"


int		main(void)
{
	T(nop,
		(void)state;
	)

	T(stack_comparisons,
		t_stack_state	s;
		int				ret;
		(s = (t_stack_state){
			.wk_grid = {
				{'\0', 'A', 'B', 'B', 'B', '\0'},
				{'A', 'A', 'C', '\0', 'B', 'G',},
				{'A', '\0', 'C', 'C', 'G', 'G',},
				{'E', '\0', 'C', 'D', 'G', '\0',},
				{'E', 'D', 'D', 'D', 'F', '\0',},
				{'E', 'E', 'F', 'F', 'F', '\0',},
			},
			.ret = ((t_stack_grid){
				{'\0', 'A', '\0', '\0', 'D', '\0',},
				{'A', 'A', 'D', 'D', 'D', '\0',},
				{'A', 'C', 'B', 'B', 'B', '\0',},
				{'E', 'C', 'C', 'G', 'B', '\0',},
				{'E', 'C', 'G', 'G', '\0', 'F',},
				{'E', 'E', 'G', 'F', 'F', 'F',},
			}),
			.best = 14
		});
		printf("wk_grid is : \n");
		aux_print_stack_grid(s.wk_grid);
		printf("ret grid is : \n");
		aux_print_stack_grid(s.ret);
		ret = compare_stacks(&s);
		printf("ret is : %d\n", ret);
		assert_false(ret);
	)

    return (
		_cmocka_run_group_tests(
					"TEST_ARR", TEST_ARR,
					test_index, 0, 0
		)
	);
}
