/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:14:11 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/14 15:46:15 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_before(t_double dchar, int *i)
{
	while (dchar.char_n[*i] && dchar.char_n[*i] != 'c')
	{
		ft_putchar(dchar.char_n[*i]);
		*i = *i + 1;
	}
	if (dchar.char_n[*i] != 'c' && *i == 0)
		*i = *i + 1;
}

static void	free_dchar(t_double dchar, t_variable **lst)
{
	if (dchar.char_n[0])
		free(dchar.char_n);
	if ((*lst)->conv == 'C')
		free(dchar.char_w);
	if ((*lst)->conv == 'c' && (*lst)->size[0] == 'l')
		free(dchar.char_w);
}

static int	put_after(t_double dchar, int *i)
{
	int j;

	j = 0;
	while (dchar.char_n[*i])
	{
		ft_putchar(dchar.char_n[*i]);
		*i = *i + 1;
		j++;
	}
	return (j);
}

int			putwchar(t_double dchar, t_variable **lst)
{
	int i;
	int count;
	int j;
	int tmp;

	i = 0;
	count = 0;
	j = 0;
	while (dchar.char_n[i])
	{
		put_before(dchar, &i);
		count = i;
		while (dchar.char_n[i + j] == 'c')
			j++;
		i += j;
		tmp = ft_putwstr(dchar.char_w, j);
		if (tmp == -1)
			return (-1);
		count += tmp;
		count += put_after(dchar, &i);
	}
	if (count == 0 && ((*lst)->conv == 'C' || (*lst)->conv == 'c'))
		count = 1;
	free_dchar(dchar, lst);
	return (count);
}
