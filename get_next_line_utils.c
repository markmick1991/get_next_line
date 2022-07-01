/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psomjitr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:57:40 by psomjitr          #+#    #+#             */
/*   Updated: 2022/03/29 22:26:30 by psomjitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_findnl(char *s)
{
	while (*s && *s != '\n')
		s++;
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	const char	target = c;

	if (!s)
		return (NULL);
	while (*s != target)
		if (*s++ == '\0')
			return (NULL);
	return ((char *)s);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*ret;
	char	*p_stash;
	char	*p_buffer;
	char	*p_ret;

	if (!stash)
	{
		stash = (char *)malloc(sizeof(char));
		*stash = '\0';
	}
	if (!stash || !buffer)
		return (NULL);
	ret = malloc(sizeof(char *) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!ret)
		return (NULL);
	p_stash = stash;
	p_buffer = buffer;
	p_ret = ret;
	while (*p_stash != '\0')
		*p_ret++ = *p_stash++;
	while (*p_buffer != '\0')
		*p_ret++ = *p_buffer++;
	*p_ret = '\0';
	free(stash);
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	const char	*p_s = s;

	while (*p_s != '\0')
		p_s++;
	return (p_s - s);
}
