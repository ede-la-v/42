/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_j_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:06:42 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 14:32:01 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fuintmax_t(va_list args, t_variable **lst)
{
	if ((*lst)->conv == 'o')
		return (ft_itoa_gen_u(va_arg(args, uintmax_t), 8));
	if ((*lst)->conv == 'u')
		return (ft_itoa_gen_u(va_arg(args, uintmax_t), 10));
	if ((*lst)->conv == 'O')
		return (ft_itoa_gen_u(va_arg(args, uintmax_t), 8));
	if ((*lst)->conv == 'U')
		return (ft_itoa_gen_u(va_arg(args, uintmax_t), 10));
	if ((*lst)->conv == 'x')
		return (ft_itoa_gen_u(va_arg(args, uintmax_t), 16));
	if ((*lst)->conv == 'X')
		return (ft_itoa_gen_bx(va_arg(args, uintmax_t), 16));
	return (NULL);
}

char	*fintmax_t(va_list args, t_variable **lst)
{
	(void)(**lst);
	return (ft_itoa_gen(va_arg(args, intmax_t)));
}

char	*fsize_t(va_list args, t_variable **lst)
{
	if ((*lst)->conv == 'o')
		return (ft_itoa_gen_u(va_arg(args, size_t), 8));
	if ((*lst)->conv == 'u')
		return (ft_itoa_gen_u(va_arg(args, size_t), 10));
	if ((*lst)->conv == 'O')
		return (ft_itoa_gen_u(va_arg(args, size_t), 8));
	if ((*lst)->conv == 'U')
		return (ft_itoa_gen_u(va_arg(args, size_t), 10));
	if ((*lst)->conv == 'x')
		return (ft_itoa_gen_u(va_arg(args, size_t), 16));
	if ((*lst)->conv == 'X')
		return (ft_itoa_gen_bx(va_arg(args, size_t), 16));
	return (ft_itoa_gen(va_arg(args, size_t)));
}

char	*fint(va_list args, t_variable **lst)
{
	char	c_to_string[2];

	if ((*lst)->conv == 'o')
		return (ft_itoa_gen_u_int(va_arg(args, int), 8));
	if ((*lst)->conv == 'u')
		return (ft_itoa_gen_u_int(va_arg(args, int), 10));
	if ((*lst)->conv == 'x')
		return (ft_itoa_gen_u_int(va_arg(args, int), 16));
	if ((*lst)->conv == 'X')
		return (ft_itoa_gen_bx_int(va_arg(args, int), 16));
	if ((*lst)->conv == 'c')
	{
		c_to_string[0] = va_arg(args, int);
		c_to_string[1] = '\0';
		return (ft_strdup(c_to_string));
	}
	return (ft_itoa_gen(va_arg(args, int)));
}

char	*long_int(va_list args, t_variable **lst)
{
	if ((*lst)->conv == 'D')
		return (ft_itoa_gen(va_arg(args, long int)));
	if ((*lst)->conv == 'O')
		return (ft_itoa_gen_u(va_arg(args, long int), 8));
	if ((*lst)->conv == 'U')
		return (ft_itoa_gen_u(va_arg(args, long int), 10));
	return (NULL);
}
