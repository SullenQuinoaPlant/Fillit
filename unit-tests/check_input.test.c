//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
	T(nop,
		(void)state;
	)

	T(valid_sample_1,
		t_mino *ret;

		assert_true(\
			(ret = check_input(\
				"./check_input_invalid_sample_1")));
		if (ret)
			free(ret);
	)

	T(invalid_sample_1,
		t_mino *ret;

		assert_false(\
			(ret = check_input(\
				"./check_input_invalid_sample_1")
			)
		);
		if (ret)
			free(ret);
	)	
    return (\
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,\
								test_index, 0, 0)\
	);
}
