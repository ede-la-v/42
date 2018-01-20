/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:47:47 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 14:46:54 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_variable	*new_variable(void)
{
	t_variable	*variable;

	variable = (t_variable *)malloc(sizeof(t_variable));
	if (variable)
	{
		bzero(variable->flag, 6);
		variable->width = -1;
		variable->precision = -1;
		bzero(variable->size, 3);
		variable->conv = '0';
		variable->next = NULL;
		variable->error = 0;
		return (variable);
	}
	return (NULL);
}

void		free_lst(t_variable **lst)
{
	t_variable *tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
}
