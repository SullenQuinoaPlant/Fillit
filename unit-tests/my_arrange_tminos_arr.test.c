//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#include <strings.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
	T(no_tmino,
		t_mino ar[1];

		ar[0].ar[0][0] = TMINO_STR_END;
		my_arrange_tminos_arr(ar);
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
		 	{'\0', '\0', '\0', '#'}}
		});
		printf("one : \n"); aux_print_tmino(one);
		(res = (t_mino){
			.ar = {
			{'#', '#', '\0', '\0'},
			{'\0', '#', '\0', '\0'},
		 	{'\0', '#', '\0', '\0'},
		 	{'\0', '\0', '\0', '\0'}}
		});
		printf("res : \n"); aux_print_tmino(res);

		memset(ar, 0, sizeof(ar));
		ar[0] = one;
		ar[1].ar[0][0] = TMINO_STR_END;
		printf("t_mino string:\n");
		aux_print_tmino_string(ar);
		my_arrange_tminos_arr(ar);
		printf("t_mino string after arranging :\n");
		aux_print_tmino_string(ar);
		
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
		 	{'\0', '\0', '\0', '#'}}
		});
		printf("one : \n"); aux_print_tmino(one);
		(two = (t_mino){
			.ar = {
			{'\0', '\0', '\0', '\0'},
			{'\0', '#', '#', '#'},
		 	{'\0', '\0', '#', '\0'},
		 	{'\0', '\0', '\0', '\0'}}
		});
		memset(ar, 0, sizeof(ar));
		ar[0] = one;
		ar[1] = two;
		ar[2].ar[0][0] = TMINO_STR_END;
		printf("tmino input string \n");
		aux_print_tmino_string(ar);

		(res_arr = (t_mino[3]){
			(t_mino){
				.ar = {
				{'#', '#', '\0', '\0'},
				{'\0', '#', '\0', '\0'},
		 		{'\0', '#', '\0', '\0'},
		 		{'\0', '\0', '\0', '\0'}}
			},
			(t_mino){
				.ar = {
				{'#', '#', '#', '\0'},
				{'\0', '#', '\0', '\0'},
		 		{'\0', '\0', '\0', '\0'},
		 		{'\0', '\0', '\0', '\0'}}
			},
			(t_mino){
				.ar = {TMINO_STR_END}
			}
		});
		printf("t_mino res strig:\n");
		aux_print_tmino_string(res_arr);

		my_arrange_tminos_arr(ar);
		printf("t_mino string after arranging :\n");
		aux_print_tmino_string(ar);
		
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
		 	{'\0', '\0', '\0', '#'}}
		});
		printf("one : \n"); aux_print_tmino(one);
		(res = (t_mino){
			.ar = {
			{'#', '#', '\0', '\0'},
			{'\0', '#', '\0', '\0'},
		 	{'\0', '#', '\0', '\0'},
		 	{'\0', '\0', '\0', '\0'}}
		});
		printf("res : \n"); aux_print_tmino(res);

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

		printf("t_mino string:\n");
		aux_print_tmino_string(ar);
		my_arrange_tminos_arr(ar);
		printf("t_mino string after arranging :\n");
		aux_print_tmino_string(ar);
		
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
//		my_arrange_tminos_arr(ar);
//		assert_false(memcmp(ar[0].ar, res.ar, sizeof(t_mino)));
//	)

    return (
		_cmocka_run_group_tests(
				"TEST_ARR", TEST_ARR,
				test_index, 0, 0
		)
	);
}
