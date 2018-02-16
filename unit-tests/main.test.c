//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 20
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
	T(nop,
		(void)state;
	)

	T(no_input,
		testee_main(1, ((char*[2]){"prog_nameh", ""}));
	)

	T(bad_file_name,
		testee_main(1, (char*[1]){"this_is_not_a_file"});
	)

	T(check_input_invalid_sample_1,
		testee_main(1, (char*[1]){"check_input_invalid_sample_1"});
	)

	T(check_input_overlength_sample,
		testee_main(1, (char*[1]){"check_input_overlength_sample"});
	)

	T(stack_tminos_1_tmino,
		testee_main(1, (char*[1]){"stack_tminos_1_tmino"});
	)

	T(stack_tminos_4_tminos,
		testee_main(1, (char*[1]){"stack_tminos_4_tminos"});
	)

	T(check_input_valid_sample_1,
		testee_main(1, (char*[1]){"check_input_valid_sample_1"});
	)

    return (
		_cmocka_run_group_tests(
					"TEST_ARR", TEST_ARR,
					test_index, 0, 0
		)
	);
}
