/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:53:52 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/16 17:52:06 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *final;
	t_list *tmp;
	t_list *tmp2;

	if (lst)
	{
		tmp = f(lst);
		final = ft_lstnew(tmp->content, tmp->content_size);
		tmp2 = final;
		lst = lst->next;
	}
	while (lst)
	{
		tmp = f(lst);
		final->next = ft_lstnew(tmp->content, tmp->content_size);
		final = final->next;
		lst = lst->next;
	}
	return (tmp2);
}
