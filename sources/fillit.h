#ifndef H_H
# define H_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# include "libft.h"

/*everything should be changed if this is changed.*/
# define TMINO_MAX_CT 26


/*input processing :*/
/*BUFF_SZ is :
** 26 * 4 * 5 (tminos)
** + 25 (empty lines)
** + 1 (file too long)*/
# define BUFF_SZ TMINO_MAX_CT * 4 * 5 + TMINO_MAX_CT - 1 + 1
# define TMINO_STR_END '\1'


typedef strut	s_pos {
	int	i;
	int	j;
}				t_s_pos;

typedef struct	s_tetramino {
	uint64_t	minobits;
	int			h;
	int			w;
}				t_mino;

/*t_mino stack maximum dimensions :*/
/*	high upper limit (could probably be reduced)
 *	assuming one square block 4 * 4 
 *	per two t_mino (can fit any combination of two in 
 *	one square block)*/

# define GRID_WIDTH 16 / 16
# define GRID_HEIGHT 16 + 4 /*padding*/

typedef
uint16_t	t_stack_grid[GRID_HEIGHT];

/* best is stored as an index (not length)*/
# define WORST_BEST 14

typedef struct	s_stack_state {
	t_mino			*tminos;
	t_stack_grid	wk_grid;
	t_s_pos			wk_pos[TMINO_MAX_CT];
	int				best;
	t_s_pos			*ret_pos;
}				t_stack_state;

/*functions*/
void
	my_arrange_tminos_arr(
		t_mino *arr);
int
	my_check_input(
		int ac, char *av[], t_mino *ret_ar);
void
	my_print_stack(
		t_tsg_ptr to_print, int side);
t_tsg_ptr
	my_stack_tminos(
		t_mino *ts, int *sz);
void
	my_usage(
		int i);

/*usage constants :*/
# define MESSAGES 4
/*usage message codes :*/
# define USAGE_DEFAULT 0
# define USAGE_ARG_COUNT 1
# define USAGE_BAD_FILE 2
# define USAGE_BAD_TETRAMINOS 3

#endif
