/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:33:53 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/20 14:06:25 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1[0] && !s2[0])
		return (0);
	if (!s1[0])
		return (-1);
	if (!s2[0])
		return (1);
	while (s1[i] || s2[i])
	{
		if ((s1[i] && !s2[i]) || (unsigned char)s1[i] > (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if ((s2[i] && !s1[i]) || (unsigned char)s2[i] > (unsigned char)s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
