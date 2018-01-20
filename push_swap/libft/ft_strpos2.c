/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:46:54 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/01 19:40:19 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strpos2(const char *haystack, char needle, char needle2)
{
	unsigned int i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle || haystack[i] == needle2)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
