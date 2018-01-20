/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_size_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:31:23 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 19:51:42 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_size(char *format, t_variable *variable, int *i)
{
	char c;

	c = format[*i];
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
	{
		variable->size[0] = c;
		*i = *i + 1;
		if ((c == 'h' || c == 'l') && format[*i] == c)
		{
			variable->size[1] = format[*i];
			*i = *i + 1;
		}
	}
}

static int	is_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	if (c == 'D' || c == 'O' || c == 'U' || c == 'C' || c == 'c' || c == 'S')
		return (1);
	if (c == 's' || c == 'p' || c == '%' || c == 'n')
		return (1);
	return (0);
}

int			fill_conv(char *format, t_variable *variable, int *i)
{
	char c;

	c = format[*i];
	if (is_conv(c))
	{
		if (c == 'p')
		{
			variable->conv = 'x';
			variable->flag[0] = '#';
			variable->size[0] = 'l';
			variable->error = 1;
		}
		else
			variable->conv = c;
		*i = *i + 1;
		return (1);
	}
	return (-1);
}
