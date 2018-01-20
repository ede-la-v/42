/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_ll_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:33:05 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 16:47:25 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*long_long(va_list args, t_variable **lst)
{
	(void)(**lst);
	return (ft_itoa_gen(va_arg(args, long long)));
}

char	*unsigned_long_long(va_list args, t_variable **lst)
{
	if ((*lst)->conv == 'o')
		return (ft_itoa_gen_u(va_arg(args, unsigned long long), 8));
	if ((*lst)->conv == 'u')
		return (ft_itoa_gen_u(va_arg(args, unsigned long long), 10));
	if ((*lst)->conv == 'O')
		return (ft_itoa_gen_u(va_arg(args, unsigned long long), 8));
	if ((*lst)->conv == 'U')
		return (ft_itoa_gen_u(va_arg(args, unsigned long long), 10));
	if ((*lst)->conv == 'x')
		return (ft_itoa_gen_u(va_arg(args, unsigned long long), 16));
	if ((*lst)->conv == 'X')
		return (ft_itoa_gen_bx(va_arg(args, unsigned long long), 16));
	return (NULL);
}

char	*flong(va_list args, t_variable **lst)
{
	(void)(**lst);
	return (ft_itoa_gen(va_arg(args, long)));
}

char	*unsigned_long(va_list args, t_variable **lst)
{
	if ((*lst)->conv == 'o')
		return (ft_itoa_gen_u(va_arg(args, unsigned long), 8));
	if ((*lst)->conv == 'O')
		return (ft_itoa_gen_u(va_arg(args, unsigned long), 8));
	if ((*lst)->conv == 'u')
		return (ft_itoa_gen_u(va_arg(args, unsigned long), 10));
	if ((*lst)->conv == 'U')
		return (ft_itoa_gen_u(va_arg(args, unsigned long), 10));
	if ((*lst)->conv == 'x')
		return (ft_itoa_gen_u(va_arg(args, unsigned long), 16));
	if ((*lst)->conv == 'X')
		return (ft_itoa_gen_bx(va_arg(args, unsigned long), 16));
	return (NULL);
}
