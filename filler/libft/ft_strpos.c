/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:46:54 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/22 12:14:02 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strpos(const char *haystack, const char *needle)
{
	unsigned int i;
	unsigned int j;

	if (needle[0] == '\0')
		return (-1);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && haystack[i + j])
				j++;
			if (!needle[j])
				return (i);
		}
		i++;
	}
	return (-1);
}
