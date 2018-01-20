/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_appendix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:53:01 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/21 19:50:16 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			check(int **tab, t_int nb)
{
	int i;

	i = 0;
	if (nb.b != 0)
		return (0);
	while (i < nb.a - 1)
	{
		if (tab[0][i] > tab[0][i + 1])
			return (0);
		i++;
	}
	return (1);
}

int			check_end(int **tab, t_int len)
{
	int i;

	i = 0;
	if (check(tab, len))
		return (1);
	while (++i < len.a)
	{
		if (tab[0][i] < tab[0][i - 1])
			return (0);
	}
	i = 0;
	while (++i < len.b)
	{
		if (tab[1][i] > tab[1][i - 1])
			return (0);
	}
	if (tab[0][0] < tab[1][0])
		return (0);
	if (tab[1][len.b - 1] != -2147483648)
		return (0);
	while (len.b)
		pa(tab, &len);
	return (1);
}

static void	loop_min(int **tab, t_int *minmax, t_int *len)
{
	if (tab[1][1] != minmax->a - 1 && minmax->a != -2147483648)
	{
		if (tab[1][0] == minmax->a)
			pa(tab, len);
		while (tab[1][0] != minmax->a - 1)
			recu2(tab, len);
	}
}

static void	loop_max(int **tab, t_int *minmax, t_int *len, int num_max)
{
	if (tab[0][1] != minmax->b + 1 && minmax->b != num_max)
	{
		if (tab[0][0] == minmax->b)
			pb(tab, len);
		while (tab[0][0] != minmax->b + 1)
		{
			recu(tab, len);
		}
	}
}

void		put_num(int **tab, t_int *minmax, t_int *len, int num_max)
{
	if (tab[0][0] == minmax->a || tab[1][0] == minmax->a)
	{
		loop_min(tab, minmax, len);
		if (tab[0][0] == minmax->a)
			pb(tab, len);
		if (minmax->a == -2147483649 + (len->a + len->b) / 2)
			minmax->a = 100;
		else
			minmax->a = minmax->a + 1;
	}
	else if (tab[0][0] == minmax->b || tab[1][0] == minmax->b)
	{
		loop_max(tab, minmax, len, num_max);
		if (tab[1][0] == minmax->b)
			pa(tab, len);
		if (minmax->b == -2147483648 + (len->a + len->b) / 2)
			minmax->b = 100;
		else
			minmax->b = minmax->b - 1;
	}
}
