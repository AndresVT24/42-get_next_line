/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 00:02:21 by ervillca          #+#    #+#             */
/*   Updated: 2026/04/28 23:09:51 by ervillca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_before_end(char *stash)
{
	char	*line;
	int		i;
	int		size;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		size = i + 2;
	else
		size = i + 1;
	line = malloc(sizeof(char) * size);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, size);
	return (line);
}

char	*ft_after_end(char *stash)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash[i + 1])
		return (free(stash), NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!tmp)
		return (free(stash), NULL);
	i++;
	j = 0;
	while (stash[i])
		tmp[j++] = stash[i++];
	tmp[j] = '\0';
	free(stash);
	return (tmp);
}

char	*ft_read_stash(int fd, char *stash)
{
	char	*tmp;
	char	*buffer;
	ssize_t	status;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	status = 1;
	while (status > 0 && !ft_isfinished(stash))
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[status] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_before_end(stash);
	stash = ft_after_end(stash);
	return (line);
}