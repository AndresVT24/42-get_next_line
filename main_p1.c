/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:48:40 by ervillca          #+#    #+#             */
/*   Updated: 2026/04/28 20:42:47 by ervillca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("p1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("[%d] %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}