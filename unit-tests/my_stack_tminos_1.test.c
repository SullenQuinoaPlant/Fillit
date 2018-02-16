//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"
#include "auxilliaries.h"

typedef struct	wrap_t_stac_grid {
	t_stack_grid	ar;
}				s_wrap_t_s_g;

void	set_grid(char *p)
{
	int		i;

	i = -1;
	while (++i < MAX_STACK_WIDTH * MAX_STACK_HEIGHT)
		if (p[i] == 0)
			p[i] = '.';
}

int		main(void)
{
	const size_t	mem_chunk =
		MAX_STACK_WIDTH * MAX_STACK_HEIGHT;

	T(nop,
		assert_true(1);
	)

	T(one_tmino,
		t_mino	*input_arr;
		char	(*res)[MAX_STACK_WIDTH];
		s_wrap_t_s_g ref = ((s_wrap_t_s_g){
			.ar = {
				{'A'},
				{'A'},
				{'A'},
				{'A'},
			}
		});

		set_grid((char*)ref.ar);
		printf("ref grid is :\n");
		aux_print_stack_grid(ref.ar);

		(input_arr = (t_mino[2]){
			(t_mino){
				.ar = {
				{'#', '\0', '\0', '\0'},
				{'#', '\0', '\0', '\0'},
		 		{'#', '\0', '\0', '\0'},
		 		{'#', '\0', '\0', '\0'}},
				.h = 4,
				.w = 1
			},
			(t_mino){
				.ar = {TMINO_STR_END}
			}
		});
		printf("attemtping to stack\n");
		if (res = my_stack_tminos_1(input_arr))
		{
			printf("res is :\n");
			aux_print_stack_grid(res);
			free(res);
			assert_memory_equal(res, &ref, mem_chunk);
		}
		else
			fail_msg("res evaluated to NULL \n");
	)

    return (
		_cmocka_run_group_tests(
					"TEST_ARR", TEST_ARR,
					test_index, 0, 0
		)
	);
}
