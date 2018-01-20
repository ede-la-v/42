/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:36:06 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/07 18:56:06 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_dioux(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	if (c == 'D' || c == 'O' || c == 'U')
		return (1);
	return (0);
}

void		precision(t_variable **lst, char **str, intmax_t var_int)
{
	char			*zero;
	unsigned long	i;
	char			*tmp;

	i = 0;
	if ((*lst)->precision == -1)
		return ;
	if ((*lst)->conv == 's' || (*lst)->conv == 'S')
		*str = ft_strsub(*str, 0, (*lst)->precision);
	if (is_dioux((*lst)->conv))
	{
		if ((*lst)->precision > (long)ft_strlen(*str))
		{
			zero = (char *)malloc((*lst)->precision - ft_strlen(*str) + 1);
			zero[(*lst)->precision - ft_strlen(*str)] = '\0';
			while (i < (*lst)->precision - ft_strlen(*str))
				zero[i++] = '0';
			tmp = *str;
			*str = ft_strjoin(zero, tmp);
			free(zero);
			if (var_int != -2)
				free(tmp);
		}
	}
}

static void	join_min(t_variable **lst, char **str, intmax_t var_int,
		char *minus)
{
	char *tmp;

	if (var_int == -1)
	{
		tmp = *str;
		*str = ft_strjoin(minus, tmp);
		if (is_dioux((*lst)->conv) && var_int != -2)
			free(tmp);
	}
	else if ((*lst)->flag[4] == '+')
	{
		minus[0] = '+';
		tmp = *str;
		*str = ft_strjoin(minus, tmp);
		if (is_dioux((*lst)->conv) && var_int != -2)
			free(tmp);
	}
	else if ((*lst)->flag[3] == ' ')
	{
		minus[0] = ' ';
		tmp = *str;
		*str = ft_strjoin(minus, tmp);
		if (is_dioux((*lst)->conv) && var_int != -2)
			free(tmp);
	}
}

void		plus(t_variable **lst, char **str, intmax_t var_int)
{
	char minus[2];

	minus[0] = '-';
	minus[1] = '\0';
	if ((*lst)->conv == 'd' || (*lst)->conv == 'D' || (*lst)->conv == 'i')
		join_min(lst, str, var_int, minus);
}
