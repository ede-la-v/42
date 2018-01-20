/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_recu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:40:54 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/21 19:59:41 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	norm(int **tab, t_int *len, int *nb, int i)
{
	int tmp;

	if (i == 2)
	{
		sa(tab, len->a);
		rra(tab, len->a);
		*nb = *nb + 1;
	}
	else if (i > 2)
	{
		pb(tab, len);
		while (i > 1)
		{
			tmp = recu(tab, len);
			*nb = *nb + tmp;
			i = i - tmp;
		}
		pa(tab, len);
		rra(tab, len->a);
		*nb = *nb + 1;
	}
}

int		recu(int **tab, t_int *len)
{
	int i;
	int nb;

	i = 1;
	nb = 0;
	while (tab[0][0] > tab[0][i])
		i++;
	if (i < 2)
	{
		rra(tab, len->a);
		nb++;
	}
	norm(tab, len, &nb, i);
	return (nb);
}

void	norm2(int **tab, t_int *len, int *nb, int i)
{
	int tmp;

	if (i == 2)
	{
		sb(tab, len->b);
		rrb(tab, len->b);
		*nb = *nb + 1;
	}
	else if (i > 2)
	{
		pa(tab, len);
		while (i > 1)
		{
			tmp = recu2(tab, len);
			*nb = *nb + tmp;
			i = i - tmp;
		}
		pb(tab, len);
		rrb(tab, len->b);
		*nb = *nb + 1;
	}
}

int		recu2(int **tab, t_int *len)
{
	int i;
	int nb;

	i = 1;
	nb = 0;
	while (tab[1][0] < tab[1][i])
		i++;
	if (i < 2)
	{
		rrb(tab, len->b);
		nb++;
	}
	norm(tab, len, &nb, i);
	return (nb);
}
