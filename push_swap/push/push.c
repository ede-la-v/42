/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:46:25 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/23 12:59:07 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	handle_args(int argc, char **argv, char **str)
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

static void	free_all(char **args, char *str, int **tab)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	free(tab[0]);
	free(tab[1]);
	free(str);
	free(tab);
}

int			main(int argc, char **argv)
{
	int		i;
	int		**tab;
	char	**args;
	char	*str;

	i = 0;
	str = NULL;
	if (argc > 1)
	{
		handle_args(argc, argv, &str);
		args = NULL;
		args = ft_strsplit(str, ' ');
		while (args[i])
			i++;
		tab = (int **)malloc(sizeof(int *) * 2);
		tab[0] = (int *)malloc(sizeof(int) * i);
		tab[1] = (int *)malloc(sizeof(int) * i);
		i = -1;
		while (args[++i])
			tab[0][i] = ft_atoi(args[i]);
		divide(tab, i + 1);
		free_all(args, str, tab);
	}
	return (0);
}
