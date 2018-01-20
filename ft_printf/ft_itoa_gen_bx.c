/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:57:26 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 14:27:09 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_array(char *str, uintmax_t b, int base, uintmax_t i)
{
	str[i] = '\0';
	i--;
	while (b)
	{
		if (b % base > 9)
			str[i] = b % base - 10 + 65;
		else
			str[i] = b % base + 48;
		b /= base;
		i--;
	}
}

char		*ft_itoa_gen_bx(uintmax_t n, int base)
{
	uintmax_t	a;
	uintmax_t	b;
	uintmax_t	i;
	char		*str;

	i = 0;
	a = n;
	b = a;
	if (a == 0)
		return ("0");
	while (a)
	{
		a /= base;
		i++;
	}
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	fill_array(str, b, base, i);
	return (str);
}
