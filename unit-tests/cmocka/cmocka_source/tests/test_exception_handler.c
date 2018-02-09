#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdlib.h>

struct test_segv {
    int x;
    int y;
};

static void test_segfault_recovery(void **state)
{
    struct test_segv *s = NULL;

    (void) state; /* unused */

    s->x = 1;
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_segfault_recovery),
<<<<<<< HEAD
        cmocka_unit_test(test_segfault_recovery),
        cmocka_unit_test(test_segfault_recovery),
=======
>>>>>>> ffbf144e3c4a58b24ec6db8182fec4746d50d9a9
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
