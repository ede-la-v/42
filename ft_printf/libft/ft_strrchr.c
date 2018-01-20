/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:52:13 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/20 14:04:44 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s[0] && c == '\0')
		return ((char *)s);
	while (s[i])
		++i;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&(s[i]));
		i--;
	}
	return (NULL);
}
