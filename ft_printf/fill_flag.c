/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:51:51 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/14 14:06:07 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(char c)
{
	if (c == '#' || c == '0' || c == ' ' || c == '-' || c == '+')
		return (1);
	return (0);
}

static void	put_flag(char c, char flag, int pos, t_variable *variable)
{
	if (c == flag)
	{
		(variable->flag[pos] = flag);
	}
}

int			fill_flag(char *format, t_variable *variable, int *i)
{
	while (format[*i] && is_flag(format[*i]))
	{
		put_flag(format[*i], '#', 0, variable);
		put_flag(format[*i], '0', 1, variable);
		put_flag(format[*i], '-', 2, variable);
		put_flag(format[*i], ' ', 3, variable);
		put_flag(format[*i], '+', 4, variable);
		*i = *i + 1;
	}
	return (1);
}
