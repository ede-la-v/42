/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:28:57 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/14 15:26:00 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_s(va_list args, t_variable **lst)
{
	char *str;

	(void)(**lst);
	str = va_arg(args, char *);
	return (str);
}

char	*void_s(va_list args, t_variable **lst)
{
	(void)(**lst);
	(void)args;
	return (NULL);
}

char	*gen_null(void)
{
	char *str_n;

	str_n = malloc(7);
	if (!str_n)
		return (NULL);
	str_n[0] = '(';
	str_n[1] = 'n';
	str_n[2] = 'u';
	str_n[3] = 'l';
	str_n[4] = 'l';
	str_n[5] = ')';
	str_n[6] = '\0';
	return (str_n);
}
