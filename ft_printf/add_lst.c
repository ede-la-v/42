/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:37:00 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 10:06:03 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_lst(t_variable **variable, t_variable *new)
{
	t_variable *tmp;

	if (*variable == NULL)
	{
		*variable = new;
	}
	else
	{
		tmp = *variable;
		while ((*variable)->next)
			*variable = (*variable)->next;
		(*variable)->next = new;
		*variable = tmp;
	}
}
