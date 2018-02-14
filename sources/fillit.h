#ifndef H_H
# define H_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

typedef struct	s_tetramino {
	unsigned char	ar[4][4];

}				t_mino;


/*usage message codes : */
# define USAGE_ARG_COUNT 1
# define USAGE_BAD_FILE 2
# define USAGE_BAD_TETRAMINOS 3

# define TMINO_MAX_CT 26 /*MAX_ .. should be changed
						   if this is changed.*/
/*t_mino stack maximum dimensions :*/
/*	high upper limit (could be reduced)
 *	assuming one square block 4 * 4 
 *	per t_mino*/
# define MAX_STACK_WIDTH 24
# define MAX_STACK_HEIGHT 20
# define TMINO_STR_END '\1'

/*BUFF_SZ is 26 * 4 * 5 + 25(empty lines) + 1 (file too long)*/
#define BUFF_SZ TMINO_MAX_CT * 4 * 5 + TMINO_MAX_CT - 1 + 1

typedef char (t_stack_grid[MAX_STACK_HEIGHT][MAX_STACK_WIDTH]);
typedef struct	s_stack_state {
	t_stack_grid	wk_grid;
	char			(*ret)[MAX_STACK_WIDTH];
	int				best;
}				t_stack_state;

/*functions*/
void	my_arrange_tminos_arr(t_mino *arr);
t_mino	*my_check_input(int ac, char *av[]);
void	my_usage(int i);


#endif
