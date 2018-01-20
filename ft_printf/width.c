/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:09:14 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/14 15:36:58 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_a(t_variable **lst, char **str, intmax_t var_int)
{
	int a;

	a = 0;
	if ((*lst)->flag[0] == '#' && ((*lst)->conv == 'x' || (*lst)->conv == 'X'))
		if ((*str)[0] != '0' || (*str)[1] != '\0')
			a = 2;
	if (var_int == -1 || (*lst)->flag[4] == '+' || (*lst)->flag[3] == ' ')
		a = 1;
	if ((*lst)->flag[1] != '0')
	{
		hash(lst, str, var_int);
		plus(lst, str, var_int);
		a = 0;
	}
	if ((*str)[0] == '\0' && (*lst)->conv == 'c')
		a = 1;
	return (a);
}

static void	join_padd(t_variable **lst, char **str, intmax_t var, char *padd)
{
	char	*tmp;
	int		i;

	i = 0;
	if ((*lst)->flag[2] == '-')
	{
		tmp = *str;
		*str = ft_strjoin(tmp, padd);
	}
	else if ((*lst)->flag[1] == '0')
	{
		while (padd[i])
			padd[i++] = '0';
		tmp = *str;
		*str = ft_strjoin(padd, tmp);
	}
	else
	{
		tmp = *str;
		*str = ft_strjoin(padd, tmp);
	}
	if (is_dioux((*lst)->conv) && var != -2)
		free(tmp);
}

void		width(t_variable **lst, char **str, intmax_t var_int)
{
	char			*padd;
	unsigned long	i;
	int				a;

	i = 0;
	a = set_a(lst, str, var_int);
	if (*str == NULL)
		return ;
	if ((*lst)->width != -1 && (*lst)->width > (long)ft_strlen(*str) + a)
	{
		padd = (char *)malloc((*lst)->width - ft_strlen(*str) + 1 - a);
		padd[(*lst)->width - ft_strlen(*str) - a] = '\0';
		while (i < (*lst)->width - ft_strlen(*str) - a)
			padd[i++] = ' ';
		i = 0;
		join_padd(lst, str, var_int, padd);
		free(padd);
		(*lst)->error = 20;
	}
	if ((*lst)->flag[1] == '0')
	{
		hash(lst, str, var_int);
		plus(lst, str, var_int);
	}
}
