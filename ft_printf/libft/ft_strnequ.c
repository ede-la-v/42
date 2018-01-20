/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:32:35 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/17 10:29:04 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	if (!s1[0] && !s2[0])
		return (1);
	if (!s1[0] || !s2[0])
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((s1[i] && !s2[i]) || s1[i] > s2[i])
			return (0);
		if ((s2[i] && !s1[i]) || s2[i] > s1[i])
			return (0);
		i++;
	}
	return (1);
}
