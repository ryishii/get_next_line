/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishiiryoutoku <ishiiryoutoku@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 06:25:17 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/24 03:25:43 by ishiiryouto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t  i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2, size_t n)
{
	size_t  len;
	char    *res;
	size_t  i;
	size_t  j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		len = ft_strlen(s2);
	else if (s2 == NULL)
		len = ft_strlen(s1);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (*s1 != '\0' && s1 != NULL)
		res[i++] = *s1++;
	j = 0;
	while (*s2 != '\0' && s2 != NULL && j++ < n)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	size_t  i;
	size_t  len;
	char    *res;

	len = ft_strlen(s);
	i = 0;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = s[i]; 
		i++;
	}
	res[i] = '\0';
	return (res);
}