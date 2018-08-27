/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 03:52:41 by mbellaic          #+#    #+#             */
/*   Updated: 2018/08/27 04:11:24 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# include "libft.h"

/*
** everything should be changed if this is changed.
*/

# define TMINO_MAX_CT 26

/*
** input processing :
*/
/*
** BUFF_SZ is :
** 26 * 4 * 5 (tminos)
** + 25 (empty lines)
** + 1 (file too long)
*/
# define BUFF_SZ TMINO_MAX_CT * 4 * 5 + TMINO_MAX_CT - 1 + 1

typedef struct		s_pos {
	int				i;
	int				j;
}					t_s_pos;

typedef struct		s_tetramino {
	char			ar[4][4];
	uint64_t		bits;
	int				h;
	int				w;
}					t_mino;

/*
** t_mino stack maximum dimensions :
*/
/*
** high upper limit (could probably be reduced)
**	assuming one square block 4 * 4
**	per two t_mino (can fit any combination of two in
**	one square block)
*/

# define GRID_WIDTH 16 / 16
# define GRID_HEIGHT 16 + 4

/*
**padding
*/

typedef uint16_t	t_stack_grid[GRID_HEIGHT];

/*
** best is stored as an index (not length)
*/

# define WORST_BEST 14

typedef struct		s_stack_state {
	t_mino			*tminos;
	t_stack_grid	wk_grid;
	t_s_pos			wk_pos[TMINO_MAX_CT];
	int				best;
	t_s_pos			*ret_pos;
}					t_stack_state;

/*
** functions
*/
void				arrange_tmino(t_mino *mino);

int					check_input(int ac, char *av[], t_mino *ret_ar);

int					compare_best(t_stack_state *s);

int					print_stack(int side, t_s_pos *mino_pos, t_mino *minos);

int					stack_tminos(t_mino *tminos, t_s_pos *ret_ar);

void				usage(int i);

/*
** usage constants :
*/

# define MESSAGES 6

/*
** usage message codes :
*/

# define USAGE_SIMPLE 5
# define USAGE_DEFAULT 0
# define USAGE_ARG_COUNT USAGE_SIMPLE
# define USAGE_BAD_FILE USAGE_SIMPLE
# define USAGE_BAD_TETRAMINOS USAGE_SIMPLE
# define USAGE_SYS_ERR USAGE_SIMPLE

#endif
