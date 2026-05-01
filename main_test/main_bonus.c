/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:44:05 by ervillca          #+#    #+#             */
/*   Updated: 2026/05/01 17:41:40 by ervillca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

static void	print_line(char *label, char *line)
{
	if (!line)
		printf("%s -> NULL\n", label);
	else
	{
		printf("%s -> %s", label, line);
		if (line[0] && line[ft_strlen(line) - 1] != '\n')
			printf("\n");
		free(line);
	}
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("bonusA.txt", O_RDONLY);
	fd2 = open("bonusB.txt", O_RDONLY);
	fd3 = open("bonusC.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		printf("Error abriendo archivos\n");
		return (1);
	}

	print_line("fd1", get_next_line(fd1));
	print_line("fd2", get_next_line(fd2));
	print_line("fd3", get_next_line(fd3));
	print_line("fd1", get_next_line(fd1));
	print_line("fd2", get_next_line(fd2));
	print_line("fd3", get_next_line(fd3));
	print_line("fd1", get_next_line(fd1));
	print_line("fd2", get_next_line(fd2));
	print_line("fd3", get_next_line(fd3));
	print_line("fd1", get_next_line(fd1));
	print_line("fd2", get_next_line(fd2));
	print_line("fd3", get_next_line(fd3));

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}