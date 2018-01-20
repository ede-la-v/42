/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:42:10 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 14:16:52 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_variables(char *format, t_variable **lst)
{
	int			i;
	t_variable	*tmp;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp = new_variable();
			i++;
			if (fill_flag(format, tmp, &i) == -1)
				tmp->error = -1;
			fill_width(format, tmp, &i);
			fill_precision(format, tmp, &i);
			fill_size(format, tmp, &i);
			if (fill_conv(format, tmp, &i) == -1)
				tmp->error = -2;
			add_lst(lst, tmp);
		}
		else
			i++;
	}
}
