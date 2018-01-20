/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:46:45 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/20 14:00:33 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char *ps;

	ps = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ps[i] == (unsigned char)c)
			return ((void *)(ps + i));
		i++;
	}
	return (NULL);
}
