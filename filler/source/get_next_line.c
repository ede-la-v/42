/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-la-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:16:31 by ede-la-v          #+#    #+#             */
/*   Updated: 2017/12/27 14:16:26 by ede-la-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

static int	create_buf(char *buf, int fd, int *condition)
{
	int ret;
	int pos;

	if (buf[1] == '\0' && buf[0] == '\0')
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-2);
		if (ret != BUFF_SIZE)
			*condition = 0;
		buf[ret] = '\0';
	}
	else
	{
		pos = ft_strpos(buf, "\n");
		ft_memmove(buf, buf + pos + 1, BUFF_SIZE - pos);
	}
	pos = ft_strpos(buf, "\n");
	return (pos);
}

static char	*create_next_string(char *buf, int pos, int *condition)
{
	char *tmp;

	if (pos > -1)
	{
		tmp = ft_strsub(buf, 0, pos);
		*condition = 0;
		if (pos == BUFF_SIZE - 1)
			bzero(buf, BUFF_SIZE);
	}
	else
	{
		tmp = ft_strdup(buf);
		bzero(buf, BUFF_SIZE);
	}
	return (tmp);
}

int			get_next_line(const int fd, char **line)
{
	char		*tmp;
	char		*cpy;
	int			condition;
	int			pos;
	static char	buf[BUFF_SIZE + 1];

	if (!line)
		return (-1);
	condition = 1;
	*line = malloc(1);
	(*line)[0] = '\0';
	while (condition)
	{
		if ((pos = create_buf(buf, fd, &condition)) == -2)
			return (-1);
		tmp = create_next_string(buf, pos, &condition);
		cpy = *line;
		*line = ft_strjoin(cpy, tmp);
		free(cpy);
		free(tmp);
	}
	if (pos == -1 && !(*line)[0])
		return (0);
	return (1);
}
