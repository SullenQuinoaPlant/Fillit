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
			{'.', '.', '.', '.'},
			{'.', '.', '#', '#'},
		 	{'.', '.', '.', '#'},
		 	{'.', '.', '.', '#'}}
		});
		(res = (t_mino){
			.ar = {
			{'#', '#', '.', '.'},
			{'.', '#', '.', '.'},
		 	{'.', '#', '.', '.'},
		 	{'.', '.', '.', '.'}}
		});

		memset(ar, 0, sizeof(ar));
		ar[0] = one;
		my_arrange_tminos_arr(ar);
		assert_false(0);
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
