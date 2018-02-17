//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 20
#include "cmocka/my_macro_overlay.h"

#include "auxilliaries.h"

int		main(void)
{
	T(valid_sample_1,
		t_mino 	*ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "./check_input_valid_sample_1"}))));
		if (ret)
			free(ret);
	)

	T(valid_sample_2,
		t_mino	*ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "check_input_valid_sample_2"}))));
		if (ret)
			free(ret);
	)

	T(valid_sample_3,
		t_mino *ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "./check_input_valid_sample_2"}))));
		if (ret)
			free(ret);
	)

	T(invalid_sample_1,
		t_mino *ret;

		assert_null(
			(ret = my_check_input(2, ((char*[2]){"", "./check_input_invalid_sample_1"}))));
		if (ret)
			free(ret);
	)

	T(bad_filename_1,
		t_mino *ret;

		assert_null(
			(ret = my_check_input(2, ((char*[2]){"", "does_not_exist"}))));
		if (ret)
			free(ret);
	)

	T(file_too_long,
		t_mino *ret;

		assert_null(
			(ret = my_check_input(2, ((char*[2]){"", "check_input_overlength_sample"}))));
		if (ret)
			free(ret);
	)

	T(file_max_length,
		t_mino *ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "check_input_max_length_sample"}))));
		if (ret)
			free(ret);
	)

	T(stack_tminos_1_tmino,
		t_mino *ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "stack_tminos_1_tmino"}))));
		if (ret)
		{
			printf("input is :\n");
			system("cat stack_tminos_1_tmino");
			printf("after processing : \n");
			aux_print_tmino_string(ret);
			free(ret);
		}
	)

	T(stack_tminos_2_tmino,
		t_mino *ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "stack_tminos_2_tminos"}))));
		if (ret)
		{
			printf("input is :\n");
			system("cat stack_tminos_2_tminos");
			printf("after processing : \n");
			aux_print_tmino_string(ret);
			free(ret);
		}
	)

	T(stack_tminos_4_tmino,
		t_mino *ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "stack_tminos_4_tminos"}))));
		if (ret)
		{
			printf("input is :\n");
			system("cat stack_tminos_4_tminos");
			printf("after processing : \n");
			aux_print_tmino_string(ret);
			free(ret);
		}
	)

	T(stack_tminos_4_tmino_2,
		t_mino *ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "stack_tminos_4_tminos_2"}))));
		if (ret)
		{
			printf("input is :\n");
			system("cat stack_tminos_4_tminos_2");
			printf("after processing : \n");
			aux_print_tmino_string(ret);
			free(ret);
		}
	)

	T(check_input_valid_sample_1,
		t_mino *ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "check_input_valid_sample_1"}))));
		if (ret)
		{
			printf("input is :\n");
			system("cat check_input_valid_sample_1");
			printf("after processing : \n");
			aux_print_tmino_string(ret);
			free(ret);
		}
	)

	T(check_input_valid_sample_2,
		t_mino *ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "check_input_valid_sample_2"}))));
		if (ret)
		{
			printf("input is :\n");
			system("cat check_input_valid_sample_2");
			printf("after processing : \n");
			aux_print_tmino_string(ret);
			free(ret);
		}
	)

	T(check_input_valid_sample_3,
		t_mino *ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "check_input_valid_sample_3"}))));
		if (ret)
		{
			printf("input is :\n");
			system("cat check_input_valid_sample_3");
			printf("after processing : \n");
			aux_print_tmino_string(ret);
			free(ret);
		}
	)

    return (
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,
								test_index, 0, 0
		)
	);
}
