/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ervillca <ervillca@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:23:28 by ervillca          #+#    #+#             */
/*   Updated: 2026/04/29 20:40:04 by ervillca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;

	i = 1;
	line = get_next_line(0);
	while (line != NULL)
	{
		printf("linea %d: [%s]", i, line);
		free(line);
		i++;
		line = get_next_line(0);
	}
	return (0);
}