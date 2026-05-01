/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:23:28 by ervillca          #+#    #+#             */
/*   Updated: 2026/05/01 16:29:18 by ervillca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../get_next_line.h"

int	main(void)
{
	char	*line;
	int		n;

	n = 1;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		printf("Linea %d: %s", n, line);
		if (line[0] && line[ft_strlen(line) - 1] != '\n')
			printf("\n");
		free(line);
		n++;
	}
	return (0);
}