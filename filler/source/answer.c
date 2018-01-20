/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:19:27 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/27 14:12:58 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	output(t_coord result)
{
	char *tmp;

	if (result.x != -1000)
	{
		tmp = ft_itoa(result.x);
		ft_putstr(tmp);
		write(1, " ", 1);
		free(tmp);
		tmp = ft_itoa(result.y);
		ft_putstr(tmp);
		free(tmp);
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		write(1, "0 0\n", 4);
		return (1);
	}
}

int	answer(t_turn cr)
{
	t_coord i;
	t_coord win;
	t_coord result[2];

	i.y = -1;
	win.x = check_win(cr.tab, cr.player);
	result[0].x = -1000;
	win.y = 0;
	while (cr.tab[++i.y])
	{
		i.x = -1;
		while (cr.tab[i.y][++i.x])
		{
			if (cr.tab[i.y][i.x] == cr.player)
			{
				result[1] = if_player(cr, i, win.x, win.y);
				win.y = 1;
				if (result[1].x != -1000 && win.x)
					return (0);
				if (result[1].x != -1000 || result[1].y != -1000)
					result[0] = result[1];
			}
		}
	}
	return (output(result[0]));
}
