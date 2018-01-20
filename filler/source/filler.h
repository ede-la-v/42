/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 11:03:41 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/27 15:12:24 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_turn
{
	char	**tab;
	t_coord *piece;
	char	player;
	t_coord tab_size;
}				t_turn;

int				handle_output();
char			handle_first(char **line);
int				handle_turn(char **line, char player);
t_coord			get_tab_size(char **line);
t_coord			*create_piece(char **tab_piece);
t_coord			get_piece_size(char **line);
char			**create_tab(char **line, t_coord tab_size);
char			**create_tab2(char **line, t_coord tab_size);
int				answer(t_turn cr);
int				check_piece(t_turn cr, t_coord i);
int				get_next_line(const int fd, char **line);
char			adv(char c);
int				ft_abs(int nb);
int				score_at(t_turn cr, int pos, t_coord i);
int				score_def(t_turn cr, int pos, t_coord i);
int				check_win(char **tab, char player);
t_coord			if_player(t_turn cr, t_coord i, int win, int debut);
t_coord			if_not();
void			free_curr(t_turn cr, char **tab_piece);

#endif
