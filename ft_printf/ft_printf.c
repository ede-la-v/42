/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:47:12 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/14 14:27:55 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_normal(char c, int *count, int *i)
{
	ft_putchar(c);
	*count = *count + 1;
	*i = *i + 1;
}

static int	if_var(const char *format, int *i, va_list args, t_variable **lst)
{
	int count;
	int tmp;

	count = 0;
	if (format[*i] != '%')
		put_normal(format[*i], &count, i);
	else
	{
		if ((*lst)->error == -2)
		{
			free_lst(lst);
			return (-1);
		}
		if ((*lst)->conv != 'n')
		{
			tmp = display(args, lst);
			if (tmp == -1)
				return (-1);
			count += tmp;
		}
		*i += 2 + ft_strpos2(format + *i + 1, (*lst)->conv, 'p');
		free_lst(lst);
	}
	return (count);
}

static void	handle_n(va_list args, int count)
{
	int *data;

	data = va_arg(args, int *);
	*data = count;
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_variable	*lst;
	int			i;
	int			count;
	int			erreur;

	lst = NULL;
	va_start(args, format);
	i = 0;
	count = 0;
	fill_variables((char *)format, &lst);
	while (format[i])
	{
		if (format[i] == '%' && lst && lst->conv == 'n')
			handle_n(args, count);
		erreur = if_var(format, &i, args, &lst);
		if (erreur == -1)
			return (-1);
		else
			count += erreur;
	}
	return (count);
}
