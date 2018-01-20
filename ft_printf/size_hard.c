/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:43:57 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/14 15:43:35 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nb_bit(int bit[5], int max)
{
	int i;

	i = 0;
	while (bit[i] != -1)
		i++;
	if (i > max)
		return (0);
	i = 0;
	while (bit[i] != -1)
		write(1, &bit[i++], 1);
	return (i);
}

int			ft_putwchar(int bit[5], wchar_t arg, int max)
{
	if (arg < 0 || arg > 2097151)
		return (-1);
	else if ((arg > -1 && arg < 128) || MB_CUR_MAX < 2)
		bit[0] = arg;
	else if (arg < 2048 || MB_CUR_MAX < 3)
	{
		bit[0] = (0b11 << 6) | ((arg & 0b11111000000) >> 6);
		bit[1] = (0b1 << 7) | (arg & 0b00000111111);
	}
	else if (arg < 65536 || MB_CUR_MAX < 4)
	{
		bit[0] = (0b111 << 5) | ((arg & (0b1111 << 12)) >> 12);
		bit[1] = (0b1 << 7) | (arg & 0b111111 << 6) >> 6;
		bit[2] = (0b1 << 7) | (arg & 0b111111);
	}
	else
	{
		bit[0] = (0b1111 << 4) | ((arg & (0b1111 << 18)) >> 18);
		bit[1] = (0b1 << 7) | (arg & 0b111111 << 12) >> 12;
		bit[2] = (0b1 << 7) | (arg & 0b111111 << 6) >> 6;
		bit[3] = (0b1 << 7) | (arg & 0b111111);
	}
	return (nb_bit(bit, max));
}

int			ft_putwstr(wchar_t *str, int max)
{
	int count;
	int bit[5];
	int i;
	int j;
	int tmp;

	count = 0;
	i = 0;
	while (str[i] && count < max)
	{
		j = 0;
		while (j < 5)
			bit[j++] = -1;
		tmp = ft_putwchar(bit, str[i], max - count);
		if (tmp == -1)
			return (-1);
		if (tmp == 0)
			return (count);
		count += tmp;
		i++;
	}
	return (count);
}

wchar_t		*fwint_t(va_list args, t_variable **lst)
{
	wchar_t truc;
	wchar_t *truc2;

	(void)(**lst);
	truc = va_arg(args, int);
	truc2 = (wchar_t *)malloc(2 * sizeof(wchar_t));
	truc2[0] = truc;
	truc2[1] = '\0';
	return (truc2);
}

wchar_t		*wchar_t_s(va_list args, t_variable **lst)
{
	(void)(**lst);
	return (va_arg(args, wchar_t*));
}
