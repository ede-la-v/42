/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:56:41 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/27 15:37:21 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		first_max(t_coord *max, int debut)
{
	if (debut == 0)
	{
		max->x = 2147483647;
		max->y = 2147483647;
	}
}

static t_coord	if_win(t_turn cr, t_coord i, int tmp)
{
	t_coord result;
	char	*tmp2;

	result.x = -cr.piece[tmp].y + i.y;
	result.y = -cr.piece[tmp].x + i.x;
	tmp2 = ft_itoa(result.x);
	ft_putstr(tmp2);
	free(tmp2);
	write(1, " ", 1);
	tmp2 = ft_itoa(result.y);
	ft_putstr(tmp2);
	write(1, "\n", 1);
	free(tmp2);
	return (result);
}

static t_coord	if_at(t_coord hash, t_coord i, t_coord *max, t_coord score_tmp)
{
	t_coord result;

	result.x = -hash.y + i.y;
	result.y = -hash.x + i.x;
	max->y = score_tmp.y;
	max->x = score_tmp.x;
	return (result);
}

static t_coord	if_def(t_coord hash, t_coord i, t_coord *max, t_coord score_tmp)
{
	t_coord result;

	result.x = -hash.y + i.y;
	result.y = -hash.x + i.x;
	max->y = score_tmp.y;
	return (result);
}

t_coord			if_player(t_turn cr, t_coord i, int win, int debut)
{
	t_coord			result;
	int				tmp;
	static t_coord	max;
	t_coord			score_tmp;

	first_max(&max, debut);
	tmp = check_piece(cr, i);
	if (tmp != -1)
	{
		if (tmp != -1 && win)
			return (if_win(cr, i, tmp));
		score_tmp.x = score_at(cr, tmp, i);
		score_tmp.y = score_def(cr, tmp, i);
		if (tmp != -1 && score_tmp.x < max.x)
			result = if_at(cr.piece[tmp], i, &max, score_tmp);
		else if (tmp != -1 && score_tmp.x == max.x && score_tmp.y < max.y)
			result = if_def(cr.piece[tmp], i, &max, score_tmp);
		else
			result = if_not();
	}
	else
		result = if_not();
	return (result);
}
