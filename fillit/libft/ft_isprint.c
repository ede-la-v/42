/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:43:10 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/09 16:14:59 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	return (c > 31 && c < 127);
}
