/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 00:02:21 by ervillca          #+#    #+#             */
/*   Updated: 2026/04/28 20:15:39 by ervillca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_before_end(char* stash)
{
	char *line;
	int	i;
    int size;
    
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
	return line;
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

char    *get_next_line(int fd)
{
    static  char* stash;
    char*   tmp;
    char*   buffer;
    char*   line;
    ssize_t status;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    status = 1;
    while (status > 0 && !ft_isfinished(stash))
    {
        status = read(fd, buffer, BUFFER_SIZE);
        if (status == -1)
        {
            free(buffer);
            free(stash);
            stash = NULL;
            return (NULL);
        }    
        buffer[status] = '\0';
        tmp = stash;
        stash = ft_strjoin(stash, buffer);
        free(tmp);
        if (!stash)
        {
            free(buffer);
            return (NULL);
        }
    }
    free(buffer);
    line = ft_before_end(stash);
    stash = ft_after_end(stash);
    return (line);
}