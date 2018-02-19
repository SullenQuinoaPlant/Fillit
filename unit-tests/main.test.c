//main is defined (see compiler invocation)
#undef main

#define HOW_MANY_TESTS 20
#include "cmocka/my_macro_overlay.h"

int		main(int ac, char* av[])
{
	T(nop,
		(void)state;
	)

	T(no_input,
		testee_main(1, ((char*[2]){"prog_name", ""}));
	)

	T(bad_file_name,
		testee_main(2, (char*[2]){"prog_name", "this_is_not_a_file"});
	)

	T(check_input_invalid_sample_1,
		testee_main(2, (char*[2]){"", "check_input_invalid_sample_2"});
	)

	T(check_input_overlength_sample,
		testee_main(2, (char*[2]){"", "check_input_overlength_sample"});
	)

	T(stack_tminos_1_tmino,
		testee_main(2, (char*[2]){"", "stack_tminos_1_tmino"});
	)

	T(stack_tminos_4_tminos,
		testee_main(2, (char*[2]){"", "stack_tminos_4_tminos"});
	)

	T(stack_tminos_4_tminos_2,
		testee_main(2, (char*[2]){"", "stack_tminos_4_tminos_2"});
	)

	T(check_input_valid_sample_1,
		testee_main(2, (char*[2]){"", "check_input_valid_sample_1"});
	)

	T(check_input_valid_sample_2,
		testee_main(2, (char*[2]){"", "check_input_valid_sample_2"});
	)

	T(check_input_valid_sample_3,
		testee_main(2, (char*[2]){"", "check_input_valid_sample_3"});
	)

	T(any,
		testee_main(2, (char*[2]){"", "any"});
	)

	run_test_arr(ac, av);
}
