/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:03:20 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/23 14:57:35 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static void	output(int **tab, t_int nb)
{
	if (check(tab, nb))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

static int	free_tab(int ***tab)
{
	free((*tab)[0]);
	free((*tab)[1]);
	free(*tab);
	return (-1);
}

static int	fill_tab(char **args, int **tab)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (args[i])
	{
		if (check_int(ft_atoi(args[i])) == -1)
			a = -1;
		tab[0][i] = ft_atoi(args[i]);
		i++;
	}
	return (a);
}

int			create_tab(int argc, char **argv, int **tab)
{
	int		i;
	int		a;
	char	**args;
	char	*str;

	i = 0;
	str = NULL;
	a = 0;
	handle_args(argc, argv, &str);
	if (check_digit(str) == -1)
		a = -1;
	args = ft_strsplit(str, ' ');
	while (args[i])
		i++;
	tab[0] = (int *)malloc(sizeof(int) * i);
	tab[1] = (int *)malloc(sizeof(int) * i);
	if (a == 0 && fill_tab(args, tab) == -1)
		a = -1;
	if (a == 0 && check_table(tab[0], i) == -1)
		a = -1;
	free_all(&args, &str);
	if (a == -1)
		return (free_tab(&tab));
	return (i);
}

int			main(int argc, char **argv)
{
	int		**tab;
	t_int	nb;
	char	*line;

	nb.b = 0;
	if (argc > 1)
	{
		tab = (int **)malloc(sizeof(int *) * 2);
		if ((nb.a = create_tab(argc, argv, tab)) == -1)
			return (0);
		line = NULL;
		while (get_next_line(0, &line))
		{
			if (process(tab, &nb, line) == 0)
			{
				ft_putstr("Error\n");
				ft_strdel(&line);
				return (0);
			}
			ft_strdel(&line);
		}
		output(tab, nb);
		free_tab(&tab);
	}
	return (0);
}
