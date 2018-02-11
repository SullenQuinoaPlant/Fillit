//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 50
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
//	testee_main(0, 0);
	T(nop,
		(void)state;
	)
	T_STOP
    return (cmocka_run_group_tests(tests, NULL, NULL));
}
