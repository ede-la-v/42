/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:18:28 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/14 15:43:59 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "type.h"

static int	count_bit(wchar_t arg)
{
	if (arg < 128 || MB_CUR_MAX < 2)
		return (1);
	else if (arg < 2048 || MB_CUR_MAX < 3)
		return (2);
	else if (arg < 65536 || MB_CUR_MAX < 4)
		return (3);
	else
		return (4);
}

static void	fill_strn(char *str_n, int count)
{
	str_n[count] = '\0';
	count--;
	while (count >= 0)
	{
		str_n[count] = 'c';
		count--;
	}
}

static char	*fill_charn(wchar_t *str, t_variable **lst)
{
	int		i;
	int		count;
	char	*str_n;
	int		max;

	i = 0;
	max = (*lst)->precision;
	count = 0;
	if (!str)
		return (gen_null());
	while (str[i])
	{
		if (max > -1 && count_bit(str[i]) > max - count)
			break ;
		else
			count += count_bit(str[i]);
		i++;
	}
	str_n = (char *)malloc(count + 1);
	if (!str_n)
		return (NULL);
	fill_strn(str_n, count);
	return (str_n);
}

static void	fn_classic(t_double *str,
		char *type, va_list args, t_variable **lst)
{
	int i;

	i = 0;
	while (g_type_conv[i].arg[0] != '0')
	{
		if (ft_strcmp(type, g_type_conv[i].arg) == 0)
		{
			str->char_n = g_type_conv[i].fn(args, lst);
			str->char_w = NULL;
			if (!str->char_n)
			{
				str->char_w = (wchar_t *)malloc(sizeof(wchar_t));
				str->char_w[0] = '\0';
				str->char_n = gen_null();
			}
		}
		i++;
	}
}

t_double	search(va_list args, t_variable **lst)
{
	int			i;
	char		type[4];
	t_double	str;

	i = 0;
	type[0] = (*lst)->conv;
	type[1] = (*lst)->size[0];
	type[2] = (*lst)->size[1];
	type[3] = '\0';
	fn_classic(&str, type, args, lst);
	while (g_type_conv2[i].arg[0] != '0')
	{
		if (ft_strcmp(type, g_type_conv2[i].arg) == 0)
		{
			str.char_w = g_type_conv2[i].fn(args, lst);
			str.char_n = fill_charn(str.char_w, lst);
			if (!str.char_w)
			{
				str.char_w = (wchar_t *)malloc(sizeof(wchar_t));
				str.char_w[0] = '\0';
			}
		}
		i++;
	}
	return (str);
}
