/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 02:45:53 by mbellaic          #+#    #+#             */
/*   Updated: 2018/08/27 02:48:44 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char *	messages[MESSAGES] = {
	"usage function called\n",
	"fillit.exe requires exactly one filename as input.\n\
			the file must describe a list of tetraminos.\n",
	"could not open specified file or file was too long\n",
	"tetramino file contents invalid\n",
	"system error\n",
	"error"
};

void	usage(int i)
{
	if (i >= MESSAGES)
		i = USAGE_DEFAULT;
	ft_putstr(messages[i]);
}
