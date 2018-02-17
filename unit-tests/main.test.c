//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 20
#include "cmocka/my_macro_overlay.h"

int		search_test_arr_by_name(const char *t_name)
{
	size_t	i;

	i = 0;
	while (i < HOW_MANY_TESTS)
	{
		if (!strcmp(t_name, TEST_ARR[i].name))
			return (i);
		i++;
	}
	return (0);
}

int		search_test_arr(const char *search_for)
{
	int		ret;

	if ((ret = search_test_arr_by_name(search_for)))
		return (ret);
	else
		return ((ret = atoi(search_for)) < HOW_MANY_TESTS ? ret : 0);
}

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

	if (ac == 1)
	{
	    return (
			_cmocka_run_group_tests(
						"TEST_ARR", TEST_ARR,
						test_index, 0, 0
			)
		);
	}
	else
	{
		int		i;
		int		test_index;
		int		ret_value;

		i = 0;
		ret_value = 0;
		while (++i < ac)
		{
			test_index = search_test_arr(av[i]);
			ret_value += _cmocka_run_group_tests(av[i], &TEST_ARR[test_index], 1, 0, 0);
		}
		return (ret_value);
	}
}
