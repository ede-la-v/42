/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:07:40 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/17 10:31:43 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_space(const char *s)
{
	unsigned int	a;
	unsigned int	b;
	int				i;

	a = 0;
	while (ft_isspace(s[a]))
		a++;
	if (a == ft_strlen(s))
		return (a);
	b = ft_strlen(s) - 1;
	i = ft_isspace(s[b]);
	while (ft_isspace(s[b]))
		b--;
	return (a + ft_strlen(s) - b - 1);
}

char		*ft_strtrim(char const *s)
{
	char			*str;
	int				i;
	int				a;
	unsigned int	j;

	if (!s)
		return (NULL);
	a = count_space(s);
	str = (char *)malloc(ft_strlen(s) - a + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	j = 0;
	while (j < ft_strlen(s) - a)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
