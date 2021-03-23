/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishiiryoutoku <ishiiryoutoku@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 06:25:46 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/24 03:26:37 by ishiiryouto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int				safe_free(char **p, int res);
int				put_line(char **line, char **save, char *buf);
int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(const char *s1, const char *s2, size_t n);
size_t			ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);

#endif