/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:40:56 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/27 13:17:03 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	adv(char c)
{
	if (c == 'X')
		return ('O');
	if (c == 'O')
		return ('X');
	return ('0');
}

int		ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

t_coord	if_not(void)
{
	t_coord result;

	result.x = -1000;
	result.y = -1000;
	return (result);
}
