/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:17:54 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/20 13:49:20 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	j = 0;
	i = ft_strlen(dst);
	k = ft_strlen(dst);
	if ((unsigned int)size < k)
		k = size;
	if (!size)
		return (k + ft_strlen(src));
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if ((unsigned int)size < k)
		k = size;
	return (k + ft_strlen(src));
}
