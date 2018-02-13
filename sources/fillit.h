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
# define USAGE_BAD_FILENAME 2
# define USAGE_BAD_TETRAMINOS 3

/*t_mino stack maximum dimensions :*/
/*	high upper limit (could be reduced)
 *	assuming one square block 4 * 4 
 *	per t_mino*/
# define MAX_STACK_WIDTH 24
# define MAX_STACK_HEIGHT 20

typedef (char[MAX_STACK_HEIGHT][MAX_STACK_WIDTH]) t_stack_grid;

/*functions*/
void	my_arrange_tminos_arr(t_mino *arr);
t_mino	*my_check_input(int ac, char *av[]);
void	my_usage(int i);


#endif
