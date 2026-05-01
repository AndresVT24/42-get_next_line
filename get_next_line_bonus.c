/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:34:06 by ervillca          #+#    #+#             */
/*   Updated: 2026/05/01 14:43:40 by ervillca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stash[OPEN_MAX];
	char		*line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	stash[fd] = ft_read_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_before_end(stash[fd]);
	stash[fd] = ft_after_end(stash[fd]);
	return (line);
}