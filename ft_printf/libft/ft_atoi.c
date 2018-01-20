/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:01:44 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/11/16 13:31:27 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned int	i;
	int				a;
	unsigned int	b;

	i = 0;
	a = 1;
	b = 0;
	while (check_space(str[i]))
		i++;
	if (str[i] == '-')
		a = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		b = b * 10 + str[i] - 48;
		i++;
	}
	return (a * b);
}
