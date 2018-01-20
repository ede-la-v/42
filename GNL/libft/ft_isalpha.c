/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:11:50 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/09 19:11:55 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (64 < c && c < 91)
		return (1);
	if (96 < c && c < 123)
		return (1);
	return (0);
}