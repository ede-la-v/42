/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:57:44 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/15 18:58:11 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sa(int **tab, int nb)
{
	swap(tab[0], nb);
	write(1, "sa\n", 3);
}

void	sb(int **tab, int nb)
{
	swap(tab[1], nb);
	write(1, "sb\n", 3);
}

void	ss(int **tab, int nb1, int nb2)
{
	swap(tab[0], nb1);
	swap(tab[1], nb2);
	write(1, "ss\n", 3);
}
