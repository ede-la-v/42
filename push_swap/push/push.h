/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:00:43 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/22 19:12:33 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_int
{
	int a;
	int b;
}				t_int;

int				put_order(int *tab, int argc, int min);
void			divide(int **tab, int argc);
void			sa(int **tab, int nb);
void			sb(int **tab, int nb);
void			ss(int **tab, int nb1, int nb2);
void			ra(int **tab, int nb);
void			rb(int **tab, int nb);
void			rr(int **tab, int nb1, int nb2);
void			rra(int **tab, int nb);
void			rrb(int **tab, int nb);
void			rrr(int **tab, int nb1, int nb2);
void			pa(int **tab, t_int *len);
void			pb(int **tab, t_int *len);
void			algo(int **tab, t_int len);
void			algo1(int **tab, t_int len);
void			algo3(int **tab, t_int len);
void			algo4(int **tab, t_int len);
int				check_end(int **tab, t_int len);
int				check(int **tab, t_int nb);
void			put_num(int **tab, t_int *minmax, t_int *len, int num_max);
void			swap_them(int **tab, t_int len);
void			push_it(int **tab, t_int *len);
void			rotate_them(int **tab, t_int len, t_int minmax);
void			swap(int *tab, int nb);
void			push(int *tab1, int *tab2, int nb1, int nb2);
void			rotate(int *tab, int nb);
void			r_rotate(int *tab, int nb);
void			if_min(int **tab, t_int *len, t_int *minmax);
void			if_min2(int **tab, t_int *len, t_int *minmax, t_int *len_tmp);
int				recu(int **tab, t_int *len);
int				recu2(int **tab, t_int *len);
void			premier_tri(int **tab, t_int len);
void			premier_tri2(int **tab, t_int len);
void			set_a3(int *a, t_int len, t_int *len_tmp);
void			set_a4(int *a, t_int len, t_int *len_tmp);
void			min1(int **tab, t_int *len, t_int *len_tmp);
void			min2(int **tab, t_int *len, t_int *len_tmp);

#endif
