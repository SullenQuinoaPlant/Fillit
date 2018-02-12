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

#endif
