#ifndef H_H
# define H_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"


# define TMINO_MAX_CT 26 /*MAX_ .. should be changed
						   if this is changed.*/
/*t_mino stack maximum dimensions :*/
/*	high upper limit (could probably be reduced)
 *	assuming one square block 4 * 4 
 *	per two t_mino (can fit any combination of two in 
 *	one square block)*/
/*15 by 15 is enough because 12 by 16 is enough
*/
/*the dimensions are then increased by 3 to allow 
 * for t_mino comparison on the outer columns and
 * rows */
# define MAX_STACK_WIDTH 18
# define MAX_STACK_HEIGHT 18
# define INVALID_POS 0x80
/* best is stored as an index (not length)*/
# define WORST_BEST 14


/*input processing :*/
/*BUFF_SZ is :
** 26 * 4 * 5 (tminos)
** + 25(empty lines)
** + 1 (file too long)*/
# define BUFF_SZ TMINO_MAX_CT * 4 * 5 + TMINO_MAX_CT - 1 + 1
# define TMINO_STR_END '\1'


/*usage constants :*/
# define MESSAGES 4
/*usage message codes :*/
# define USAGE_DEFAULT 0
# define USAGE_ARG_COUNT 1
# define USAGE_BAD_FILE 2
# define USAGE_BAD_TETRAMINOS 3



typedef struct	s_tetramino {
	char	ar[4][4];
	int		h;
	int		w;
}				t_mino;

typedef char	(t_stack_grid[MAX_STACK_HEIGHT][MAX_STACK_WIDTH]);
typedef char	(*t_tsg_ptr)[MAX_STACK_WIDTH];

typedef struct	s_stack_state {
	t_mino			*tminos;
	t_stack_grid	wk_grid;
	char			(*ret)[MAX_STACK_WIDTH];
	int				best;
}				t_stack_state;

/*row_ends and col_ends store indexes*/
typedef struct	s_stack_values {
	int				row_ends[MAX_STACK_HEIGHT];
	int				col_ends[MAX_STACK_WIDTH];
	t_mino			*mino;
}				t_stack_values;

/*functions*/
void		my_arrange_tminos_arr(t_mino *arr);
t_mino		*my_check_input(int ac, char *av[]);
void		my_print_stack(t_tsg_ptr to_print, int side);
t_tsg_ptr	my_stack_tminos(t_mino *ts, int *sz);
void		my_usage(int i);


#endif
