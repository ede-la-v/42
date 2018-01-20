/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:57:26 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 15:08:23 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_array(char *str, uintmax_t b, intmax_t n, uintmax_t i)
{
	str[i] = '\0';
	i--;
	while (b)
	{
		if (b % 10 > 9)
			str[i] = b % 10 - 10 + 97;
		else
			str[i] = b % 10 + 48;
		b /= 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
}

static void	norm(intmax_t n, uintmax_t *a, uintmax_t *i)
{
	if (n < 0)
	{
		*a = -n;
		*i = *i + 1;
	}
	else
		*a = n;
}

char		*ft_itoa_gen(intmax_t n)
{
	uintmax_t	a;
	uintmax_t	b;
	uintmax_t	i;
	char		*str;

	i = 0;
	norm(n, &a, &i);
	b = a;
	if (a == 0)
		return ("0");
	while (a)
	{
		a /= 10;
		i++;
	}
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	fill_array(str, b, n, i);
	return (str);
}
