/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:05:36 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/27 15:37:14 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord	get_tab_size(char **line)
{
	t_coord tab;
	char	*tmp;
	int		i;
	int		j;

	i = 8;
	while (ft_isdigit((*line)[i]))
		i++;
	tmp = ft_strsub(*line, 8, i - 8);
	tab.y = ft_atoi(tmp);
	free(tmp);
	i++;
	j = i;
	while (ft_isdigit((*line)[i]))
		i++;
	tmp = ft_strsub(*line, j, i - j);
	tab.x = ft_atoi(tmp);
	free(tmp);
	return (tab);
}

int		handle_turn(char **line, char player)
{
	t_coord		piece_size;
	char		**tab_piece;
	t_turn		current;

	current.player = player;
	current.tab_size = get_tab_size(line);
	ft_strdel(line);
	get_next_line(0, line);
	current.tab = create_tab(line, current.tab_size);
	piece_size = get_piece_size(line);
	tab_piece = create_tab2(line, piece_size);
	current.piece = create_piece(tab_piece);
	if (answer(current))
	{
		free_curr(current, tab_piece);
		return (1);
	}
	free_curr(current, tab_piece);
	return (0);
}

char	handle_first(char **line)
{
	char a;

	a = (*line)[10];
	ft_strdel(line);
	get_next_line(0, line);
	if (a == '2')
		return ('X');
	if (a == '1')
		return ('O');
	return ('0');
}

int		handle_output(void)
{
	char *line;
	char player;

	line = NULL;
	player = -1;
	while (1)
	{
		if (get_next_line(0, &line) == 0)
		{
			ft_strdel(&line);
			return (1);
		}
		if (line[0] == '$')
			player = handle_first(&line);
		if (handle_turn(&line, player))
		{
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
	}
	return (0);
}

int		main(void)
{
	handle_output();
	return (0);
}
