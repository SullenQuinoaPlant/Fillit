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
		assert_true(\
			!check_input(\
				./check_input_invalid_sample_1));
	)
	T(invalid_sample_1,
		assert_false(!check_input(\
			./check_input_invalid_sample_1)
		);
	)	
    return (\
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,\
								test_index, 0, 0)\
	);
}
