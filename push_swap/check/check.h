/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:04:05 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/20 15:56:38 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_int
{
	int a;
	int b;
}				t_int;

int				get_next_line(const int fd, char **line);
void			r_rotate(int *tab, int nb);
void			rotate(int *tab, int nb);
void			push(int *tab1, int *tab2, int nb1, int nb2);
void			swap(int *tab, int nb);
int				check(int **tab, t_int nb);
int				process2(int **tab, t_int *nb, char *line);
int				process(int **tab, t_int *nb, char *line);
int				create_tab(int argc, char **argv, int **tab);
void			free_all(char ***args, char **str);
int				check_table(int *tab, int max);
int				check_digit(char *str);
void			handle_args(int argc, char **argv, char **str);
int				check_int(intmax_t nb);

#endif
