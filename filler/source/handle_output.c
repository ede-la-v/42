/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:41:55 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/27 15:12:08 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**create_tab(char **line, t_coord tab_size)
{
	char	**tab;
	int		i;
	int		start;

	tab = (char **)malloc(sizeof(char *) * (tab_size.y + 1));
	if (!tab)
		return (NULL);
	i = 0;
	tab[tab_size.y] = NULL;
	while (i < tab_size.y)
	{
		ft_strdel(line);
		get_next_line(0, line);
		if (ft_strpos(*line, " ") != -1)
			start = ft_strpos(*line, " ") + 1;
		else
			start = 0;
		tab[i] = ft_strsub(*line, start, tab_size.x);
		i++;
	}
	return (tab);
}

char		**create_tab2(char **line, t_coord tab_size)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(sizeof(char *) * (tab_size.y + 1));
	if (!tab)
		return (NULL);
	i = 0;
	tab[tab_size.y] = NULL;
	while (i < tab_size.y)
	{
		ft_strdel(line);
		get_next_line(0, line);
		tab[i] = ft_strsub(*line, 0, tab_size.x);
		i++;
	}
	return (tab);
}

t_coord		get_piece_size(char **line)
{
	t_coord piece;
	char	*tmp;
	int		i;
	int		j;

	i = 6;
	ft_strdel(line);
	get_next_line(0, line);
	while (ft_isdigit((*line)[i]))
		i++;
	j = i + 48;
	tmp = ft_strsub(*line, 6, i - 6);
	piece.y = ft_atoi(tmp);
	free(tmp);
	i++;
	j = i;
	while (ft_isdigit((*line)[i]))
		i++;
	tmp = ft_strsub(*line, j, i - j);
	piece.x = ft_atoi(tmp);
	free(tmp);
	return (piece);
}

static void	fill_piece(char **tab_piece, t_coord *piece, int nb)
{
	int i;
	int j;

	piece[nb].x = -1;
	i = 0;
	nb = 0;
	while (tab_piece[i])
	{
		j = 0;
		while (tab_piece[i][j])
		{
			if (tab_piece[i][j] == '*')
			{
				piece[nb].x = j;
				piece[nb].y = i;
				nb++;
			}
			j++;
		}
		i++;
	}
}

t_coord		*create_piece(char **tab_piece)
{
	int		i;
	int		j;
	int		nb;
	t_coord *piece;

	i = 0;
	nb = 0;
	while (tab_piece[i])
	{
		j = 0;
		while (tab_piece[i][j])
		{
			if (tab_piece[i][j] == '*')
			{
				nb++;
			}
			j++;
		}
		i++;
	}
	piece = (t_coord *)malloc((nb + 1) * sizeof(t_coord));
	if (!piece)
		return (NULL);
	fill_piece(tab_piece, piece, nb);
	return (piece);
}
