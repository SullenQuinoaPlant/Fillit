/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 02:45:53 by mbellaic          #+#    #+#             */
/*   Updated: 2018/09/01 04:13:52 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#DEFINE USAGE "usage: ./fillit [filename]

void	error()
{
	ft_putstr(USAGE);
}


#DEFINE ERROR "error\n"
void	error()
{
	ft_putstr(ERROR);
}
