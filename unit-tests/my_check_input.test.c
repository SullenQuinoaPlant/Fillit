//main is defined (see compiler invocation)
#undef main

#include <stdio.h>
#define HOW_MANY_TESTS 10
#include "cmocka/my_macro_overlay.h"


int		main(void)
{
	char * p = ((char*[2]){"", "./check_input_valid_sample_1"});
	printf("p[1] is : %s", p[1]);
	T(valid_sample_1,
		t_mino 	*ret;

//		int		fd;
//		fd = open("./check_input_valid_sample_1", O_RDONLY);
//		assert_int_not_equal(fd, -1);
//		int index;
//		char	buff[BUFF_SZ] = {0};
//		index = read(fd, buff, BUFF_SZ);
//		assert_true(index < BUFF_SZ);
//		assert_true(index > 0);
//		close(fd);
//		t_mino	*arr;
//		assert_true(arr = malloc((TMINO_MAX_CT + 1) * sizeof(t_mino)));
//		free(arr);
//		buff[BUFF_SZ - 1] = '\0';
//		printf("%s", buff);
		assert_true(
			(ret = my_check_input(2, ((char*[2]){"", "./check_input_valid_sample_1"}))));
		if (ret)
			free(ret);
	)

	T(valid_sample_2,
		t_mino	*ret;

		assert_true(
			(ret = my_check_input(2, ((char*[2]){"", "./check_input_valid_sample_2"}))));
		if (ret)
			free(ret);
	)

	T(valid_sample_3,
		t_mino *ret;

		assert_true(
			(ret = my_check_input(2, ((char*[2]){"", "./check_input_valid_sample_2"}))));
		if (ret)
			free(ret);
	)

	T(invalid_sample_1,
		t_mino *ret;

		assert_false(
			(ret = my_check_input(2, ((char*[2]){"", "./check_input_valid_sample_2"}))));
		if (ret)
			free(ret);
	)

    return (
		_cmocka_run_group_tests("TEST_ARR", TEST_ARR,
								test_index, 0, 0
		)
	);
}
