/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:06:11 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/23 14:57:51 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	process(int **tab, t_int *nb, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(tab[0], nb->a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(tab[1], nb->b);
	else if (ft_strcmp(line, "ss") == 0)
	{
		swap(tab[0], nb->a);
		swap(tab[1], nb->b);
	}
	else if (ft_strcmp(line, "pa") == 0)
	{
		push(tab[1], tab[0], nb->b, nb->a);
		nb->b = nb->b - 1;
		nb->a = nb->a + 1;
	}
	else if (ft_strcmp(line, "pb") == 0)
	{
		push(tab[0], tab[1], nb->a, nb->b);
		nb->b = nb->b + 1;
		nb->a = nb->a - 1;
	}
	else
		return (process2(tab, nb, line));
	return (1);
}

int	process2(int **tab, t_int *nb, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate(tab[0], nb->a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(tab[1], nb->b);
	else if (ft_strcmp(line, "rr") == 0)
	{
		rotate(tab[0], nb->a);
		rotate(tab[1], nb->b);
	}
	else if (ft_strcmp(line, "rra") == 0)
		r_rotate(tab[0], nb->a);
	else if (ft_strcmp(line, "rrb") == 0)
		r_rotate(tab[1], nb->b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		r_rotate(tab[0], nb->a);
		r_rotate(tab[1], nb->b);
	}
	else
		return (0);
	return (1);
}

int	check(int **tab, t_int nb)
{
	int i;

	i = 0;
	if (nb.b != 0)
		return (0);
	while (i < nb.a - 1)
	{
		if (tab[0][i] > tab[0][i + 1])
			return (0);
		i++;
	}
	return (1);
}
