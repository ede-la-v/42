/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 11:49:21 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/27 14:09:29 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	tmp(int tmp, int *a)
{
	if (*a == 0 || tmp < *a)
		*a = tmp;
}

int			score_at(t_turn cr, int pos, t_coord i)
{
	int		l;
	t_coord j;
	int		a;

	l = -1;
	a = 0;
	while (cr.piece[++l].x != -1)
	{
		if (l != pos)
		{
			j.y = -1;
			while (cr.tab[++j.y])
			{
				j.x = -1;
				while (cr.tab[j.y][++j.x])
				{
					if (cr.tab[j.y][j.x] == adv(cr.player))
						tmp(ft_abs(j.y - (cr.piece[l].y - cr.piece[pos].y
							+ i.y)) + ft_abs(j.x - (cr.piece[l].x -
								cr.piece[pos].x + i.x)), &a);
				}
			}
		}
	}
	return (a);
}

static int	def(t_turn cr, int l, int pos, t_coord i)
{
	int j;
	int k;

	j = 0;
	while (cr.piece[l].y - cr.piece[pos].y - i.y + j < cr.tab_size.y)
		j++;
	k = 0;
	while (cr.piece[l].y - cr.piece[pos].y - i.y + k >= 0)
		k--;
	if (k < j)
		j = k;
	k = 0;
	while (cr.piece[l].x - cr.piece[pos].x - i.x + k < cr.tab_size.x)
		k++;
	if (k < j)
		j = k;
	k = 0;
	while (cr.piece[l].x - cr.piece[pos].x - i.x + k >= 0)
		k--;
	if (k < j)
		j = k;
	return (j);
}

int			score_def(t_turn cr, int pos, t_coord i)
{
	int l;
	int j;

	l = 0;
	while (cr.piece[l].x != -1)
	{
		if (l != pos)
		{
			j = def(cr, l, pos, i);
		}
		l++;
	}
	return (j);
}
