/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_app.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 18:01:45 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/27 13:26:10 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_hash(t_coord *star, t_turn cr, t_coord i)
{
	if (star->x != star->y)
	{
		if (cr.piece[star->y].y - cr.piece[star->x].y + i.y >= cr.tab_size.y)
			return (-1);
		else if (cr.piece[star->y].y - cr.piece[star->x].y + i.y < 0)
			return (-1);
		else if (cr.piece[star->y].x - cr.piece[star->x].x +
												i.x >= cr.tab_size.x)
			return (-1);
		else if (cr.piece[star->y].x - cr.piece[star->x].x + i.x < 0)
			return (-1);
		else if (cr.tab[cr.piece[star->y].y - cr.piece[star->x].y +
				i.y][cr.piece[star->y].x - cr.piece[star->x].x + i.x] == '.')
			star->y++;
		else
			return (-1);
	}
	else
		star->y++;
	return (0);
}

int	check_piece(t_turn cr, t_coord i)
{
	t_coord star;

	star.x = 0;
	while (cr.piece[star.x].x != -1)
	{
		star.y = 0;
		while (1)
		{
			if (cr.piece[star.y].x == -1)
				return (star.x);
			if (check_hash(&star, cr, i) == -1)
				break ;
		}
		star.x++;
	}
	star.x = -1;
	return (-1);
}

int	check_win(char **tab, char player)
{
	int			i;
	int			j;
	int			tmp;
	static int	nb = 0;

	i = -1;
	tmp = 0;
	if (nb == -1)
		return (1);
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == adv(player))
				tmp++;
		}
	}
	if (tmp > nb)
		nb = tmp;
	else
		nb = -1;
	return (0);
}
