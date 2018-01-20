/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:49:51 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/23 14:54:05 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int		check_int(intmax_t nb)
{
	if (nb < -2147483648 || nb > 2147483647)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	return (0);
}

void	free_all(char ***args, char **str)
{
	int i;

	i = 0;
	while ((*args)[i])
	{
		free((*args)[i]);
		i++;
	}
	free(*args);
	free(*str);
}

int		check_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1 && str[i] != ' ' && str[i] != '-')
		{
			ft_putstr("Error\n");
			return (-1);
		}
		if (str[i] == '-' && i != 0 && ft_isdigit(str[i - 1]) != 0)
		{
			ft_putstr("Error\n");
			printf("aaa\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

void	handle_args(int argc, char **argv, char **str)
{
	int		i;
	char	*tmp;

	i = 1;
	*str = (char *)malloc(2);
	if (!str)
		return ;
	(*str)[0] = ' ';
	(*str)[1] = '\0';
	while (i < argc)
	{
		tmp = *str;
		*str = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = *str;
		*str = ft_strjoin(tmp, argv[i]);
		free(tmp);
		i++;
	}
}

int		check_table(int *tab, int max)
{
	int i;
	int j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if (i != j)
			{
				if (tab[i] == tab[j])
				{
					ft_putstr("Error\n");
					return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
