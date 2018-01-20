/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag_width_etc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:20:22 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 19:55:33 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_width(char *format, t_variable *variable, int *i)
{
	int		j;
	char	*tmp;

	j = 0;
	if (format[*i] == '*')
	{
		variable->error = 10;
		*i = *i + 1;
		return ;
	}
	while (format[*i + j] && ft_isdigit(format[*i + j]))
		j++;
	if (j == 0)
		variable->width = 0;
	else
	{
		tmp = ft_strsub(format, *i, j);
		variable->width = ft_atoi(tmp);
		free(tmp);
	}
	*i = *i + j;
}

static int	asterisk(char c, t_variable *variable, int *i)
{
	if (c == '*')
	{
		if (variable->error == 10)
			variable->error = 12;
		else
			variable->error = 11;
		*i = *i + 1;
		return (1);
	}
	return (0);
}

void		fill_precision(char *format, t_variable *variable, int *i)
{
	int		j;
	char	*tmp;

	j = 0;
	if (format[*i] == '.')
	{
		*i = *i + 1;
		if (asterisk(format[*i], variable, i))
			return ;
		while (format[*i + j] && ft_isdigit(format[*i + j]))
			j++;
		if (j == 0)
			variable->precision = 0;
		else
		{
			tmp = ft_strsub(format, *i, j);
			variable->precision = ft_atoi(tmp);
			free(tmp);
		}
		*i = *i + j;
	}
	else
		variable->precision = -1;
}
