/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:58:27 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/23 15:15:59 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		put_order(int *tab, int argc, int min)
{
	int i;
	int min_loc;
	int nb;

	i = -1;
	nb = 0;
	min_loc = 2147483647;
	while (++i < argc - 1)
	{
		if (tab[i] >= min && tab[i] <= min_loc)
			min_loc = tab[i];
	}
	i = 0;
	while (i < argc - 1)
	{
		if (tab[i] == min_loc)
		{
			tab[i] = min;
			nb++;
		}
		i++;
	}
	if (min + 2 < argc - 2147483648)
		nb *= put_order(tab, argc, min + 1);
	return (nb);
}

void	divide(int **tab, int max)
{
	t_int	len;
	int		nb;

	nb = put_order(tab[0], max, -2147483648);
	if (nb != 1)
		return ;
	len.a = max - 1;
	len.b = 0;
	if (len.a > 200)
		premier_tri2(tab, len);
	else if (len.a > 30)
		premier_tri(tab, len);
	else if (len.a < 9)
		algo1(tab, len);
	else
		algo(tab, len);
}
