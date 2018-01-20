/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:57:13 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/20 12:16:15 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ra(int **tab, int nb)
{
	rotate(tab[0], nb);
	write(1, "rra\n", 4);
}

void	rb(int **tab, int nb)
{
	rotate(tab[1], nb);
	write(1, "rrb\n", 4);
}

void	rr(int **tab, int nb1, int nb2)
{
	rotate(tab[0], nb1);
	rotate(tab[1], nb2);
	write(1, "rrr\n", 4);
}
