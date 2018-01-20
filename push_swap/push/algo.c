/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:51:45 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/22 14:37:57 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	place(int **tab, int elem, t_int len)
{
	int i;

	i = 0;
	while (i < len.a - 1 && tab[0][i] != elem)
	{
		i++;
	}
	return (i);
}

static int	place2(int **tab, int elem, t_int len)
{
	int i;

	i = 0;
	while (i < len.a - 1 && tab[0][len.a - 1 - i] != elem)
	{
		i++;
	}
	return (i);
}

static void	rotate_it(int **tab, t_int len, t_int minmax)
{
	int min;
	int max;

	min = place(tab, minmax.a, len);
	if (place(tab, minmax.a + 1, len) < min)
		min = place(tab, minmax.a + 1, len);
	if (place(tab, minmax.a + 2, len) < min)
		min = place(tab, minmax.a + 2, len);
	if (place(tab, minmax.a + 3, len) < min)
		min = place(tab, minmax.a + 3, len);
	max = place2(tab, minmax.a, len);
	if (place2(tab, minmax.a + 1, len) < max)
		max = place2(tab, minmax.a + 1, len);
	if (place2(tab, minmax.a + 2, len) < max)
		max = place2(tab, minmax.a + 2, len);
	if (place2(tab, minmax.a + 3, len) < max)
		max = place2(tab, minmax.a + 3, len);
	if (min < max)
		rra(tab, len.a);
	else
		ra(tab, len.a);
}

static void	min3(int **tab, t_int *len, t_int minmax)
{
	if (tab[1][len->b - 1] == minmax.a + 2)
		rb(tab, len->b);
	pb(tab, len);
	rrb(tab, len->b);
	if (tab[1][0] == minmax.a + 2)
		rrb(tab, len->b);
}

void		algo(int **tab, t_int len)
{
	t_int minmax;

	minmax.a = -2147483648;
	minmax.b = minmax.a + len.a + len.b - 1;
	while (1)
	{
		if (check_end(tab, len))
			return ;
		if (tab[0][0] == minmax.a)
			if_min(tab, &len, &minmax);
		else if (tab[0][0] == minmax.a + 1)
			pb(tab, &len);
		else if (tab[0][0] == minmax.a + 2)
		{
			pb(tab, &len);
			rrb(tab, len.b);
		}
		else if (tab[0][0] == minmax.a + 3)
			min3(tab, &len, minmax);
		else
			rotate_it(tab, len, minmax);
	}
}
