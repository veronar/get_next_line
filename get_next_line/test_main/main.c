/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modo <modo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:07:26 by vesingh           #+#    #+#             */
/*   Updated: 2019/09/03 18:27:22 by modo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	//sleep(10);
	return (0);
}

/*
int		main(int argc, char **argv)
{
	int fd;
	char *line;
	int i;
	int x;
	int le_bool;

	i = 0;
	if (argc == 3)
	{
		le_bool = 1;
		x = ft_atoi(argv[2]);
	}
	else if (argc == 2)
	{
		x = 1;
		le_bool = 0;
	}
	if (argc < 2)
	{
		ft_putendl("Too few args.");
		return (0);
	}
////////////////////////////////////////
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
			ft_putendl("File not found");
			return (0);
	}
////////////////////////////////////////
	while (get_next_line(fd, &line) > 0 && i < x)
	{
			ft_putstr(line);
			ft_putchar('\n');
			i = le_bool == 0 ? 0 : i + 1;
			free(line);
	}
////////////////////////////////////////
	if (close(fd) == -1)
			return (0);
	return (0);
////////////////////////////////////////
}

//Multiple FD test

int		main(int argc, char **argv)
{
	int fd1;
	int fd2;
	char *line;
	if (argc < 3)
		return (0);
////////////////////////////////////////
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		ft_putendl("File not found");
		return (0);
	}
	fd2 = open(argv[2], O_RDONLY);
	if (fd2 == -1)
	{
		ft_putendl("File not found");
		return (0);
	}
////////////////////////////////////////
	while (get_next_line(fd1, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	ft_putchar('\n');
	ft_putendl("//////////////////////////////////////////////////////////////////////////////////////");
	ft_putchar('\n');
	while (get_next_line(fd2, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
////////////////////////////////////////
	if (close(fd1) == -1)
			return (0);
	if (close(fd2) == -1)
			return (0);
	return (0);
}
*/
//FD 1/0 test
/*
int		main(void)
{
	char *line;
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	return (0);
}
*/
