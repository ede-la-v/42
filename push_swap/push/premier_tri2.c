/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_tri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:12:01 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/23 12:56:28 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	loop(int **tab, int lim, t_int *len, int tmp)
{
	int nb;

	nb = 0;
	while (nb < tmp)
	{
		if (tab[0][0] < lim)
		{
			pb(tab, len);
			nb++;
		}
		else
			rra(tab, len->a);
	}
}

void		premier_tri2(int **tab, t_int len)
{
	t_int	min;
	t_int	lim;
	t_int	last;
	int		tmp;

	min.a = -2147483648;
	lim.a = -2147483648 + len.a / 6;
	lim.b = lim.a + len.a / 6;
	min.b = lim.b + len.a / 6;
	last.a = min.b + len.a / 6;
	last.b = last.a + len.a / 6;
	tmp = len.a / 6;
	loop(tab, lim.a, &len, tmp);
	loop(tab, lim.b, &len, tmp);
	loop(tab, min.b, &len, tmp);
	loop(tab, last.a, &len, tmp);
	loop(tab, last.b, &len, tmp);
	while (len.a)
		pb(tab, &len);
	algo4(tab, len);
}
