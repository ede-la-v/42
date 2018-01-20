/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:51:45 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/23 12:54:33 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	place(int **tab, int elem, t_int *len_tmp)
{
	int i;

	i = 0;
	while (i < len_tmp->a - len_tmp->b - 1 && tab[1][i] != elem)
	{
		i++;
	}
	if (i == len_tmp->a - len_tmp->b - 1 && tab[1][i] != elem)
		return (700000000);
	return (i + 1);
}

static int	place2(int **tab, int elem, t_int len, t_int *len_tmp)
{
	int i;

	i = 0;
	while (i < len_tmp->b && tab[1][len.b - 1 - i] != elem)
	{
		i++;
	}
	if (i == len_tmp->b)
		return (700000000);
	return (i + 1);
}

static void	rotate_it(int **tab, t_int len, t_int minmax, t_int *len_tmp)
{
	int min;
	int max;

	min = place(tab, minmax.b, len_tmp);
	if (place(tab, minmax.b - 1, len_tmp) < min)
		min = place(tab, minmax.b - 1, len_tmp);
	if (place(tab, minmax.b - 2, len_tmp) < min)
		min = place(tab, minmax.b - 2, len_tmp);
	max = place2(tab, minmax.b, len, len_tmp);
	if (place2(tab, minmax.b - 1, len, len_tmp) < max)
		max = place2(tab, minmax.b - 1, len, len_tmp);
	if (place2(tab, minmax.b - 2, len, len_tmp) < max)
		max = place2(tab, minmax.b - 2, len, len_tmp);
	if (len_tmp->b == 0 || (len_tmp->b != len_tmp->a && min < max))
	{
		rrb(tab, len.b);
		len_tmp->b = len_tmp->b + 1;
	}
	else
	{
		rb(tab, len.b);
		len_tmp->b = len_tmp->b - 1;
	}
}

static void	min3(int **tab, t_int *len, t_int minmax, t_int *len_tmp)
{
	if (tab[0][len->a - 1] == minmax.b - 2)
		ra(tab, len->a);
	pa(tab, len);
	len_tmp->a = len_tmp->a - 1;
	rra(tab, len->a);
	if (tab[0][0] == minmax.b - 2)
		rra(tab, len->a);
}

void		algo3(int **tab, t_int len)
{
	t_int	minmax;
	t_int	len_tmp;
	int		a;

	minmax.b = -2147483648 + len.a + len.b - 1;
	len_tmp.a = len.b - (len.b / 4) * 3;
	len_tmp.b = 0;
	a = 0;
	while (1)
	{
		if (check_end(tab, len))
			return ;
		if (len_tmp.a == 0)
			set_a3(&a, len, &len_tmp);
		if (tab[1][0] == minmax.b && len_tmp.b != len_tmp.a)
			if_min2(tab, &len, &minmax, &len_tmp);
		else if (tab[1][0] == minmax.b - 1 && len_tmp.b != len_tmp.a)
			min1(tab, &len, &len_tmp);
		else if (tab[1][0] == minmax.b - 2 && len_tmp.b != len_tmp.a)
			min2(tab, &len, &len_tmp);
		else if (tab[1][0] == minmax.b - 3 && len_tmp.b != len_tmp.a)
			min3(tab, &len, minmax, &len_tmp);
		else
			rotate_it(tab, len, minmax, &len_tmp);
	}
}
