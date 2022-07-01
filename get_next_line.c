/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psomjitr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:54:08 by psomjitr          #+#    #+#             */
/*   Updated: 2022/03/30 08:41:16 by psomjitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *stash)
{
	char	*ret;
	char	*p_stash;
	char	*p_ret;

	if (!(*stash))
		return (NULL);
	p_stash = ft_findnl(stash);
	if (*p_stash == '\n')
		p_stash++;
	ret = (char *)malloc(sizeof(char) * (p_stash - stash + 1));
	if (!ret)
		return (NULL);
	p_ret = ret;
	p_stash = stash;
	while (*p_stash && *p_stash != '\n')
		*p_ret++ = *p_stash++;
	if (*p_stash == '\n')
		*p_ret++ = *p_stash++;
	*p_ret = '\0';
	return (ret);
}

char	*ft_new_stash(char *stash)
{
	char	*ret;
	char	*p_stash;
	char	*p_ret;

	p_stash = ft_findnl(stash);
	if (!(*p_stash))
	{
		free(stash);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (ft_strlen(stash) - (p_stash - stash) + 1));
	if (!ret)
		return (NULL);
	p_stash++;
	p_ret = ret;
	while (*p_stash)
		*p_ret++ = *p_stash++;
	*p_ret = '\0';
	free(stash);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*ret;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	r = 1;
	while (!ft_strchr(stash, '\n') && r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
			break ;
		*(buffer + r) = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	if (!stash || r < 0)
		return (NULL);
	ret = ft_new_line(stash);
	stash = ft_new_stash(stash);
	return (ret);
}
