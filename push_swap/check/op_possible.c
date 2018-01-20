/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:59:20 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/20 12:12:35 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	swap(int *tab, int nb)
{
	int tmp;

	if (nb > 1)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
}

void	push(int *tab1, int *tab2, int nb1, int nb2)
{
	int i;

	i = 0;
	if (nb1 > 0)
	{
		while (i < nb2)
		{
			tab2[nb2 - i] = tab2[nb2 - 1 - i];
			i++;
		}
		tab2[0] = tab1[0];
		i = 0;
		while (i < nb1 - 1)
		{
			tab1[i] = tab1[i + 1];
			i++;
		}
		tab1[i] = 0;
	}
}

void	r_rotate(int *tab, int nb)
{
	int tmp;
	int i;

	if (nb > 1)
	{
		i = 0;
		tmp = tab[nb - 1];
		while (i < nb)
		{
			tab[nb - 1 - i] = tab[nb - 2 - i];
			i++;
		}
		tab[0] = tmp;
	}
}

void	rotate(int *tab, int nb)
{
	int tmp;
	int i;

	if (nb > 1)
	{
		i = 0;
		tmp = tab[0];
		while (i < nb - 1)
		{
			tab[i] = tab[i + 1];
			i++;
		}
		tab[nb - 1] = tmp;
	}
}
