/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:27:47 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/14 15:46:13 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	if_wild(t_variable **lst, va_list args)
{
	int tmp;

	if ((*lst)->error == 10 || (*lst)->error == 12)
	{
		tmp = va_arg(args, int);
		if (tmp < 0)
		{
			tmp = -tmp;
			(*lst)->flag[2] = '-';
		}
		(*lst)->width = tmp;
	}
	if ((*lst)->error == 11 || (*lst)->error == 12)
		(*lst)->precision = va_arg(args, int);
}

static void	if_hash(t_double *dchar, char **str, t_variable **lst, va_list args)
{
	if_wild(lst, args);
	if ((*lst)->conv == '%')
		*str = "%";
	else
	{
		*dchar = search(args, lst);
		*str = dchar->char_n;
		if (ft_strcmp(*str, "(null)") == 0 && dchar->char_w)
		{
			(*lst)->error = 5;
			free(dchar->char_w);
			dchar->char_w = NULL;
		}
	}
}

static void	if_minus_zero(char **str, intmax_t *var_int)
{
	char *tmp;

	if (*str && (*str)[0] == '-')
	{
		*var_int = -1;
		tmp = *str;
		*str = ft_strdup(tmp + 1);
		free(tmp);
	}
	if (*str && (*str)[0] == '0' && (*str)[1] == '\0')
		*var_int = -2;
	if (*str && ((*str)[0] == '\0'))
		*var_int = -8;
}

static void	free_str(t_variable **lst, char *str, intmax_t var_int)
{
	ft_putstr(str);
	(void)var_int;
	if ((*lst)->error == 20 || (is_dioux((*lst)->conv) && var_int != -2))
		free(str);
	if ((*lst)->error == 5)
		free(str);
	if ((*lst)->conv == 'S' && (*lst)->error != 5)
		free(str);
	if ((*lst)->conv == 's' && (*lst)->size[0] == 'l' && (*lst)->error != 5)
		free(str);
}

int			display(va_list args, t_variable **lst)
{
	char		*str;
	intmax_t	var_int;
	int			a;
	t_double	dchar;

	str = NULL;
	var_int = 0;
	a = 0;
	dchar.char_w = NULL;
	if_hash(&dchar, &str, lst, args);
	if_minus_zero(&str, &var_int);
	exceptions(lst, &str);
	precision(lst, &str, var_int);
	if (str && str[0] == '\0' && (*lst)->conv == 'c')
		a = 1;
	width(lst, &str, var_int);
	dchar.char_n = str;
	if (dchar.char_w == NULL)
	{
		a += ft_strlen(str);
		free_str(lst, str, var_int);
		return (a);
	}
	else
		return (putwchar(dchar, lst));
}
