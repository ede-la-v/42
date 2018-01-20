/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:51:45 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/21 19:55:40 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	algo1(int **tab, t_int len)
{
	t_int minmax;

	minmax.a = -2147483648;
	minmax.b = minmax.a + len.a + len.b - 1;
	while (1)
	{
		if (check_end(tab, len))
			return ;
		else if (tab[0][0] == minmax.b || tab[0][0] == minmax.a ||
				tab[1][0] == minmax.b || tab[1][0] == minmax.a)
			put_num(tab, &minmax, &len, -2147483648 + len.a + len.b - 1);
		else if (tab[0][0] > tab[0][1] && tab[1][0] < tab[1][1]
				&& len.a > 1 && len.b > 1)
			ss(tab, len.a, len.b);
		else if (tab[0][0] > tab[0][1] && len.a > 1)
			sa(tab, len.a);
		else if (tab[1][0] < tab[1][1] && len.b > 1)
			sb(tab, len.b);
		else if ((len.a && tab[0][0] < (len.a + len.b) / 2 - 2147483648) ||
				(len.b && tab[1][0] >= (len.a + len.b) / 2 - 2147483648))
			push_it(tab, &len);
		else
			rotate_them(tab, len, minmax);
	}
}
