/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_appendix2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:54:18 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/22 14:24:33 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_them(int **tab, t_int len)
{
	if (tab[0][0] > tab[0][1] && tab[1][0] < tab[1][1])
		ss(tab, len.a, len.b);
	if (tab[0][0] > tab[0][1])
		sa(tab, len.a);
	if (tab[1][0] < tab[1][1])
		sb(tab, len.b);
}

void	push_it(int **tab, t_int *len)
{
	if (len->a > 0 && tab[0][0] < (len->a + len->b) / 2 - 2147483648)
		pb(tab, len);
	if (len->b > 0 && tab[1][0] >= (len->a + len->b) / 2 - 2147483648)
		pa(tab, len);
}

void	rotate_them(int **tab, t_int len, t_int minmax)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (minmax.b == -2147483648 + len.a + len.b - 1 ||
			tab[0][len.a - 1] != -2147483648 + len.a + len.b - 1)
		a = 1;
	if (minmax.a == -2147483648 || tab[1][len.b - 1] != -2147483648)
		b = 1;
	if (a && b)
		rr(tab, len.a, len.b);
	else if (b)
		rb(tab, len.b);
	else if (a)
		ra(tab, len.a);
}

void	if_min2(int **tab, t_int *len, t_int *minmax, t_int *len_tmp)
{
	pa(tab, len);
	len_tmp->a = len_tmp->a - 1;
	if (len->a > 1 && tab[0][1] == minmax->b - 1)
		sa(tab, len->a);
	if (len->a > 2 && tab[0][0] == tab[0][len->a - 1] + 1)
		ra(tab, len->a);
	if (len->a > 2 && tab[0][0] == tab[0][len->a - 1] + 1)
		ra(tab, len->a);
	minmax->b = tab[0][0] - 1;
	if (len->a > 2 && minmax->b - 1 == tab[0][len->a - 1])
		ra(tab, len->a);
}

void	if_min(int **tab, t_int *len, t_int *minmax)
{
	pb(tab, len);
	if (len->b > 1 && tab[1][1] == minmax->a + 1)
		sb(tab, len->b);
	if (len->b > 2 && tab[1][0] == tab[1][len->b - 1] - 1)
		rb(tab, len->b);
	if (len->b > 2 && tab[1][0] == tab[1][len->b - 1] - 1)
		rb(tab, len->b);
	minmax->a = tab[1][0] + 1;
	if (len->b > 2 && minmax->a + 1 == tab[1][len->b - 1])
		rb(tab, len->b);
}
