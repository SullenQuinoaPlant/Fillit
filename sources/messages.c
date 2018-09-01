/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 02:45:53 by mbellaic          #+#    #+#             */
/*   Updated: 2018/09/01 04:31:13 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define USAGE "usage: ./fillit [filename]"

void	usage(void)
{
	ft_putstr(USAGE);
}

#define ERROR "error\n"

void	error(void)
{
	ft_putstr(ERROR);
}
