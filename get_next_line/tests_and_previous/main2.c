/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:07:26 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/26 14:40:48 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while ((i = get_next_line(fd, &line)) == 1)
	{
		ft_putendl(line);
		free(line);
		printf("i = %d\n", i);
	}
	printf("i = %d\n", i);
	if (argc == 2)
		close(fd);
	sleep(60);
	return (0);
}
