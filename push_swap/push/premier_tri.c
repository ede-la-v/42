/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_tri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:12:01 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/23 12:56:42 by ede-la-v         ###   ########.fr       */
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

void		premier_tri(int **tab, t_int len)
{
	t_int	min;
	t_int	lim;
	int		tmp;

	min.a = -2147483648;
	lim.a = -2147483648 + len.a / 4;
	lim.b = lim.a + len.a / 4;
	min.b = lim.b + len.a / 4;
	tmp = len.a / 4;
	loop(tab, lim.a, &len, tmp);
	loop(tab, lim.b, &len, tmp);
	loop(tab, min.b, &len, tmp);
	while (len.a)
		pb(tab, &len);
	algo3(tab, len);
}
