//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#include <strings.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
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

		printf("t_mino ar before init :\n");
		aux_print_tmino(ar[0]);
		printf("\n");
		aux_print_tmino(ar[1]);
		memset(ar, 0, sizeof(ar));
		printf("t_mino ar after memset : \n");
		aux_print_tmino(ar[0]);
		printf("\n");
		aux_print_tmino(ar[1]);
		ar[0] = one;
		printf("t_mino string:\n");
		aux_print_tmino_string(ar);
		my_arrange_tminos_arr(ar);
		printf("t_mino string after arranging :\n");
		aux_print_tmino_string(ar);
		assert_false(memcmp(ar[0].ar, res.ar, sizeof(char[4][4])));
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
