/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 02:45:00 by mbellaic          #+#    #+#             */
/*   Updated: 2018/09/01 04:18:16 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		follow_tmino_shape(char (*ar)[4], int i, int j, uint64_t *bits)
{
	int			k;
	int			ii;
	int			jj;
	int			count;

	ar[i][j] = 0;
	*bits |= ((uint64_t)1) << (i * 16 + j);
	count = 1;
	k = -1;
	while (++k < 4)
	{
		ii = i + ((k % 3) - 1) * ((k + 1) % 2);
		ii = ii >= 0 && ii < 4 ? ii : 0;
		jj = j + ((k - 2) * (k % 2));
		jj = jj >= 0 && jj < 4 ? jj : 0;
		if (ar[ii][jj])
			count += follow_tmino_shape(ar, ii, jj, bits);
	}
	return (count);
}

static int		bad_tmino(t_mino *mino)
{
	char		ar[4][4];
	int			j;

	arrange_tmino(mino);
	ft_memcpy(ar, mino->ar, sizeof(mino->ar));
	mino->bits = 0;
	j = -1;
	while (++j < 4)
		if (ar[0][j] && follow_tmino_shape(ar, 0, j, &mino->bits) == 4)
			return (0);
	return (1);
}

static int		set_tmino_ar(const char *input, t_mino *ret_ar)
{
	int			i;
	int			j;
	int			k;
	char		c;

	i = -1;
	c = '\n';
	while (++i < TMINO_MAX_CT && c == '\n' && (j = -1))
	{
		while (++j < 4 && (k = -1))
		{
			while (++k < 4 && ((c = *input++) == '.' || c == '#'))
				ret_ar[i].ar[j][k] = c == '.' ? 0 : 'A' + i;
			if (k < 4 || (c = *input++) ^ '\n')
				return (0);
		}
		if (bad_tmino(ret_ar + i))
			return (0);
		c = *input++;
	}
	ret_ar[i].bits = 0;
	return (!c);
}

static int		get_input(const char *input, t_mino *ret_ar)
{
	int			r;
	int			fd;
	char		buff[BUFF_SZ];
	ssize_t		index;

	r = 0;
	if (((fd = open(input, O_RDONLY)) != -1) &&
		(index = read(fd, buff, BUFF_SZ)) > 0 &&
		index < BUFF_SZ)
	{
		buff[index] = 0;
		if (!(r = set_tmino_ar(buff, ret_ar)))
			error();
	}
	else
		error();
	if (fd != -1)
		close(fd);
	return (r);
}

int				check_input(int ac, char *av[], t_mino *ret_ar)
{
	if (ac ^ 2)
		usage();
	else
		return (get_input(av[1], ret_ar));
	return (0);
}
