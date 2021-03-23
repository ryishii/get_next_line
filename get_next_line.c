/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 03:35:30 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/24 03:39:25 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		safe_free(char **p, int res)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
	return (res);
}

int		put_line(char **line, char **save, char *buf)
{
	char	*tmp;
	size_t	len;

	len = ft_strchr(buf, '\n');
	tmp = *line;
	if (!(*line = ft_strjoin(*line, buf, len)))
		return (safe_free(&tmp, -1));
	safe_free(&tmp, 1);
	if (buf[len] == '\n')
	{
		tmp = *save;
		if (!(*save = ft_strdup(&buf[len + 1])))
			return (safe_free(&tmp, -1));
		return (safe_free(&tmp, 1));
	}
	return (safe_free(save, 0));
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			res;
	ssize_t		n;

	n = 0;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	res = 0;
	if (!(*line = (char*)malloc(sizeof(char) * 1)))
		return (-1);
	**line = '\0';
	if (save)
		res = put_line(line, &save, save);
	if (!(buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1))))
		res = -1;
	while (res == 0 && (n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = '\0';
		if (n == 0 || (res = put_line(line, &save, buf)) == -1)
			break ;
	}
	if (n == -1)
		res = -1;
	return (safe_free(&buf, res));
}
