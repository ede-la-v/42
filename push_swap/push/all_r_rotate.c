/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:55:06 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/22 11:41:31 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rra(int **tab, int nb)
{
	r_rotate(tab[0], nb);
	write(1, "ra\n", 3);
}

void	rrb(int **tab, int nb)
{
	r_rotate(tab[1], nb);
	write(1, "rb\n", 3);
}

void	rrr(int **tab, int nb1, int nb2)
{
	r_rotate(tab[0], nb1);
	r_rotate(tab[1], nb2);
	write(1, "rr\n", 3);
}

void	pa(int **tab, t_int *len)
{
	push(tab[1], tab[0], len->b, len->a);
	write(1, "pa\n", 3);
	len->a = len->a + 1;
	len->b = len->b - 1;
}

void	pb(int **tab, t_int *len)
{
	push(tab[0], tab[1], len->a, len->b);
	write(1, "pb\n", 3);
	len->a = len->a - 1;
	len->b = len->b + 1;
}
