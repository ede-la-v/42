/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3_appendix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 18:47:32 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/23 12:57:32 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	set_a3(int *a, t_int len, t_int *len_tmp)
{
	if (*a == 0)
		len_tmp->a = len.b / 3;
	else if (*a == 1)
		len_tmp->a = len.b / 2;
	else
		len_tmp->a = len.b;
	len_tmp->b = 0;
	*a = *a + 1;
}

void	min1(int **tab, t_int *len, t_int *len_tmp)
{
	pa(tab, len);
	len_tmp->a = len_tmp->a - 1;
}

void	min2(int **tab, t_int *len, t_int *len_tmp)
{
	pa(tab, len);
	len_tmp->a = len_tmp->a - 1;
	rra(tab, len->a);
}

void	set_a4(int *a, t_int len, t_int *len_tmp)
{
	if (*a == 0)
		len_tmp->a = len.b / 5;
	else if (*a == 1)
		len_tmp->a = len.b / 4;
	else if (*a == 2)
		len_tmp->a = len.b / 3;
	else if (*a == 3)
		len_tmp->a = len.b / 2;
	else
		len_tmp->a = len.b;
	len_tmp->b = 0;
	*a = *a + 1;
}
