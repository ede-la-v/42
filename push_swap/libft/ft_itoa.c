/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:57:26 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/16 13:39:55 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_array(char *str, unsigned int b, int n, int i)
{
	str[i] = '\0';
	i--;
	while (i)
	{
		str[i] = b % 10 + 48;
		b /= 10;
		i--;
	}
	if (n < 0)
		str[i] = '-';
	else
		str[i] = b % 10 + 48;
}

static void	check_a(int a, int *i)
{
	if (!a)
		*i = *i + 1;
}

char		*ft_itoa(int n)
{
	unsigned int	a;
	unsigned int	b;
	int				i;
	char			*str;

	i = 0;
	if (n < 0)
	{
		i++;
		a = -n;
	}
	else
		a = n;
	b = a;
	check_a(a, &i);
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
