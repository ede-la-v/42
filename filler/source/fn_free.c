/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:31:54 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/27 13:44:38 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_curr(t_turn cr, char **tab_piece)
{
	int i;

	i = 0;
	while (cr.tab[i])
		free(cr.tab[i++]);
	free(cr.tab);
	i = 0;
	while (tab_piece[i])
		free(tab_piece[i++]);
	free(tab_piece);
	free(cr.piece);
}
