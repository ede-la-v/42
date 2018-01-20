/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:22:44 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/11 16:01:25 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s_char;
	size_t	i;

	i = 0;
	s_char = (char *)s;
	while (i < n)
	{
		s_char[i] = '\0';
		i++;
	}
}