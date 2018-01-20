/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:53:57 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/14 13:48:13 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hash2(t_variable **lst, char **str, intmax_t var_int, char *tmp)
{
	if ((*lst)->flag[0] == '#' && (*lst)->conv == 'X' && var_int != -2)
	{
		if ((*str)[0] != 0 || (*str)[0] != '\0')
		{
			*str = ft_strjoin("0X", tmp);
			free(tmp);
		}
	}
	if ((*lst)->flag[0] == '#' && (*lst)->conv == 'o' && var_int != -2)
	{
		if ((*str)[0] != '0')
		{
			*str = ft_strjoin("0", tmp);
			free(tmp);
		}
	}
	if ((*lst)->flag[0] == '#' && (*lst)->conv == 'O' && var_int != -2)
	{
		if ((*str)[0] != '0')
		{
			*str = ft_strjoin("0", tmp);
			free(tmp);
		}
	}
}

void		hash(t_variable **lst, char **str, intmax_t var_int)
{
	char *tmp;

	tmp = *str;
	if ((*lst)->flag[0] == '#' && (*lst)->conv == 'x' && var_int != -2)
	{
		if ((*str)[0] != 0 || (*str)[0] != '\0')
		{
			*str = ft_strjoin("0x", tmp);
			free(tmp);
		}
		else if ((*lst)->error == 1)
		{
			*str = ft_strjoin("0x", tmp);
			free(tmp);
		}
	}
	else if ((*lst)->error == 1)
	{
		*str = ft_strjoin("0x", tmp);
		if (var_int != -2)
			free(tmp);
	}
	hash2(lst, str, var_int, tmp);
}

void		exceptions(t_variable **lst, char **str)
{
	if (*str && (*str)[0] == '0' && (*str)[1] == '\0' && (*lst)->precision == 0
			&& ((*lst)->flag[0] != '#' || ((*lst)->conv != 'o'
					&& (*lst)->conv != 'O')))
		*str = "";
	if (is_dioux((*lst)->conv) && (*lst)->precision != -1)
		(*lst)->flag[1] = '\0';
	if ((*lst)->flag[2] == '-')
		(*lst)->flag[1] = '\0';
}
