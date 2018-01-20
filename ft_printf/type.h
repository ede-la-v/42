/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:01:55 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/13 17:59:26 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef struct	s_type
{
	char arg[4];
	char *(*fn)(va_list args, t_variable **lst);
}				t_type;

typedef struct	s_type2
{
	char	arg[4];
	wchar_t *(*fn)(va_list args, t_variable **lst);
}				t_type2;

t_type g_type_conv[] =
{
	{ "dhh", &signed_char },
	{ "Dhh", &long_int },
	{ "ihh", &signed_char },
	{ "ohh", &unsigned_char },
	{ "Ohh", &long_int },
	{ "uhh", &unsigned_char },
	{ "Uhh", &long_int },
	{ "xhh", &unsigned_char },
	{ "Xhh", &unsigned_char },
	{ "dh", &fshort },
	{ "Dh", &long_int },
	{ "ih", &fshort },
	{ "oh", &unsigned_short },
	{ "Oh", &long_int },
	{ "uh", &unsigned_short },
	{ "Uh", &long_int },
	{ "xh", &unsigned_short },
	{ "Xh", &unsigned_short },
	{ "dl", &flong },
	{ "Dl", &long_int },
	{ "il", &flong },
	{ "ol", &unsigned_long },
	{ "Ol", &unsigned_long },
	{ "ul", &unsigned_long },
	{ "Ul", &unsigned_long },
	{ "xl", &unsigned_long },
	{ "Xl", &unsigned_long },
	{ "dll", &long_long },
	{ "Dll", &long_long },
	{ "ill", &long_long },
	{ "oll", &unsigned_long_long },
	{ "Oll", &unsigned_long_long },
	{ "ull", &unsigned_long_long },
	{ "Ull", &unsigned_long_long },
	{ "xll", &unsigned_long_long },
	{ "Xll", &unsigned_long_long },
	{ "dj", &fintmax_t },
	{ "Dj", &fintmax_t },
	{ "ij", &fintmax_t },
	{ "oj", &fuintmax_t },
	{ "Oj", &fuintmax_t },
	{ "uj", &fuintmax_t },
	{ "Uj", &fuintmax_t },
	{ "xj", &fuintmax_t },
	{ "Xj", &fuintmax_t },
	{ "dz", &fsize_t },
	{ "Dz", &fsize_t },
	{ "iz", &fsize_t },
	{ "oz", &fsize_t },
	{ "Oz", &fsize_t },
	{ "uz", &fsize_t },
	{ "Uz", &fsize_t },
	{ "xz", &fsize_t },
	{ "Xz", &fsize_t },
	{ "d", &fint },
	{ "i", &fint },
	{ "o", &fint },
	{ "u", &fint },
	{ "x", &fint },
	{ "X", &fint },
	{ "c", &fint },
	{ "s", &char_s },
	{ "p", &void_s },
	{ "U", &long_int },
	{ "O", &long_int },
	{ "D", &long_int },
	{ "0", &long_int }
};

t_type2 g_type_conv2[] =
{
	{ "C", &fwint_t },
	{ "S", &wchar_t_s },
	{ "cl", &fwint_t },
	{ "sl", &wchar_t_s },
	{ "0", &wchar_t_s }
};

#endif
