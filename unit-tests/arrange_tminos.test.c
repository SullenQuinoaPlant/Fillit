//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#include <strings.h>
#define HOW_MANY_TESTS 20
#include "cmocka/my_macro_overlay.h"

#include "auxilliaries.h"


#define TMINO_STR_END '\1'

static
void
	test_arrange_tminos(
		t_mino *str)
{
	while (str->ar[0][0] != TMINO_STR_END)
		arrange_tmino(str++);
}

int		main(void)
{
	T(no_tmino,
		t_mino ar[1];

		ar[0].ar[0][0] = TMINO_STR_END;
		test_arrange_tminos(ar);
	)

	T(one_tmino,
		t_mino ar[2];
		t_mino one;
		t_mino res;

		/*
		 * . . . .
		 * . . # #
		 * . . . #
		 * . . . #
		 * . . . #
		 */
		(one = (t_mino){
			.ar = {
			{'\0', '\0', '\0', '\0'},
			{'\0', '\0', '#', '#'},
		 	{'\0', '\0', '\0', '#'},
		 	{'\0', '\0', '\0', '#'}},
			.h = 0,
			.w = 0
		});
//		printf("one : \n"); aux_print_tmino(one);
		(res = (t_mino){
			.ar = {
			{'#', '#', '\0', '\0'},
			{'\0', '#', '\0', '\0'},
		 	{'\0', '#', '\0', '\0'},
		 	{'\0', '\0', '\0', '\0'}},
			.h = 3,
			.w = 2
		});
//		printf("res : \n"); aux_print_tmino(res);

		memset(ar, 0, sizeof(ar));
		ar[0] = one;
		ar[1].ar[0][0] = TMINO_STR_END;
//		printf("t_mino string:\n");
//		aux_print_tmino_string(ar);
		test_arrange_tminos(ar);
//		printf("t_mino string after arranging :\n");
//		aux_print_tmino_string(ar);
		
		assert_false(
			memcmp(ar[0].ar, res.ar, sizeof(char[4][4])));
	)

	T(two_tmino,
		t_mino ar[3];
		t_mino one;
		t_mino two;
		t_mino *res_arr;

		(one = (t_mino){
			.ar = {
			{'\0', '\0', '\0', '\0'},
			{'\0', '\0', '#', '#'},
		 	{'\0', '\0', '\0', '#'},
		 	{'\0', '\0', '\0', '#'}},
			.h = 0,
			.w = 0
		});
//		printf("one : \n"); aux_print_tmino(one);
		(two = (t_mino){
			.ar = {
			{'\0', '\0', '\0', '\0'},
			{'\0', '#', '#', '#'},
		 	{'\0', '\0', '#', '\0'},
		 	{'\0', '\0', '\0', '\0'}},
			.h = 0,
			.w = 0
		});
		memset(ar, 0, sizeof(ar));
		ar[0] = one;
		ar[1] = two;
		ar[2].ar[0][0] = TMINO_STR_END;
//		printf("tmino input string \n");
//		aux_print_tmino_string(ar);

		(res_arr = (t_mino[3]){
			(t_mino){
				.ar = {
				{'#', '#', '\0', '\0'},
				{'\0', '#', '\0', '\0'},
		 		{'\0', '#', '\0', '\0'},
		 		{'\0', '\0', '\0', '\0'}},
				.h = 3,
				.w = 2
			},
			(t_mino){
				.ar = {
				{'#', '#', '#', '\0'},
				{'\0', '#', '\0', '\0'},
		 		{'\0', '\0', '\0', '\0'},
		 		{'\0', '\0', '\0', '\0'}},
				.h = 2,
				.w = 3
			},
			(t_mino){
				.ar = {TMINO_STR_END}
			}
		});
//		printf("t_mino res strig:\n");
//		aux_print_tmino_string(res_arr);

		test_arrange_tminos(ar);
//		printf("t_mino string after arranging :\n");
//		aux_print_tmino_string(ar);
		
		assert_false(
			memcmp(ar, res_arr, sizeof(ar)));
	)

	T(max_tminos,
		t_mino	ar[TMINO_MAX_CT + 1];
		t_mino	one;
		t_mino	res_arr[TMINO_MAX_CT + 1];
		t_mino	res;
		int		i;

		(one = (t_mino){
			.ar = {
			{'\0', '\0', '\0', '\0'},
			{'\0', '\0', '#', '#'},
		 	{'\0', '\0', '\0', '#'},
		 	{'\0', '\0', '\0', '#'}},
			.h = 0,
			.w = 0
		});
//		printf("one : \n"); aux_print_tmino(one);
		(res = (t_mino){
			.ar = {
			{'#', '#', '\0', '\0'},
			{'\0', '#', '\0', '\0'},
		 	{'\0', '#', '\0', '\0'},
		 	{'\0', '\0', '\0', '\0'}},
			.h = 3,
			.w = 2
		});
//		printf("res : \n"); aux_print_tmino(res);

		memset(ar, 0, sizeof(ar));
		memset(res_arr, 0, sizeof(res_arr));
		i = -1;
		while (++i < TMINO_MAX_CT)
		{
			ar[i] = one;
			res_arr[i] = res;
		}
		ar[i].ar[0][0] = TMINO_STR_END;
		res_arr[i].ar[0][0] = TMINO_STR_END;

//		printf("t_mino string:\n");
//		aux_print_tmino_string(ar);
		test_arrange_tminos(ar);
//		printf("t_mino string after arranging :\n");
//		aux_print_tmino_string(ar);
		
		assert_false(
			memcmp(ar, res_arr, sizeof(ar))
		);
	)

/*This didn't work because of the commas in the array declarations,
 * not enclosed within parenthesis
 */
//	T(one_tmino,
//		t_mino ar[2];
//		t_mino one;
//		t_mino res;
//
//		/*
//		 * . . . .
//		 * . . # #
//		 * . . . #
//		 * . . . #
//		 * . . . #
//		 */
//		one.ar = {
//			{'.', '.', '.', '.'},
//			{'.', '.', '#', '#'},
//		 	{'.', '.', '.', '#'},
//		 	{'.', '.', '.', '#'}
//		};
//		res.ar = {
//			{'#', '#', '.', '.'},
//			{'.', '#', '.', '.'},
//		 	{'.', '#', '.', '.'},
//		 	{'.', '.', '.', '.'}
//		};
//
//		memset(ar, 0, sizeof(ar));
//		ar[0] = one;
//		test_arrange_tminos(ar);
//		assert_false(memcmp(ar[0].ar, res.ar, sizeof(t_mino)));
//	)

	T(stack_tminos_1_tmino,
		t_mino *ret;

		assert_non_null(
			(ret = my_check_input(2, ((char*[2]){"", "stack_tminos_1_tmino"}))));
		if (ret)
		{
			printf("input is :\n");
			system("cat stack_tminos_1_tmino");
			test_arrange_tminos(ret);
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
			test_arrange_tminos(ret);
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
			test_arrange_tminos(ret);
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
			test_arrange_tminos(ret);
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
			test_arrange_tminos(ret);
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
			test_arrange_tminos(ret);
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
			test_arrange_tminos(ret);
			printf("after processing : \n");
			aux_print_tmino_string(ret);
			free(ret);
		}
	)

    return (
		_cmocka_run_group_tests(
				"TEST_ARR", TEST_ARR,
				test_index, 0, 0
		)
	);
}
