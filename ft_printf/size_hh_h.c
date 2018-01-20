/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:08:00 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 18:39:37 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*signed_char(va_list args, t_variable **lst)
{
	(void)(**lst);
	return (ft_itoa_gen((signed char)va_arg(args, int)));
}

char	*unsigned_char(va_list args, t_variable **lst)
{
	if ((*lst)->conv == 'o')
		return (ft_itoa_gen_u((unsigned char)va_arg(args, int), 8));
	if ((*lst)->conv == 'u')
		return (ft_itoa_gen_u((unsigned char)va_arg(args, int), 10));
	if ((*lst)->conv == 'x')
		return (ft_itoa_gen_u((unsigned char)va_arg(args, int), 16));
	if ((*lst)->conv == 'X')
		return (ft_itoa_gen_bx((unsigned char)va_arg(args, int), 16));
	return (NULL);
}

char	*fshort(va_list args, t_variable **lst)
{
	(void)(**lst);
	return (ft_itoa_gen((short)va_arg(args, int)));
}

char	*unsigned_short(va_list args, t_variable **lst)
{
	if ((*lst)->conv == 'o')
		return (ft_itoa_gen_u((unsigned short)va_arg(args, int), 8));
	if ((*lst)->conv == 'u')
		return (ft_itoa_gen_u((unsigned short)va_arg(args, int), 10));
	if ((*lst)->conv == 'x')
		return (ft_itoa_gen_u((unsigned short)va_arg(args, int), 16));
	if ((*lst)->conv == 'X')
		return (ft_itoa_gen_bx((unsigned short)va_arg(args, int), 16));
	return (NULL);
}
