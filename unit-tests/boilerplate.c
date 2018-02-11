//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 50
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
	T(nop,
		(void)state;
	)
    return (RUN_T);
}
