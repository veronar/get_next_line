/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:06:55 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/26 15:31:44 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void		ft_no_newline(char **store, char *buff)
{
	char	*temp = NULL;

	if (*store == NULL)
	{
		*store = ft_strdup(buff);
	}
	else
	{
		temp = ft_strdup(*store);
		ft_strdel(store);
//		printf("no newline 0.0: store: = %p\n", *store);
		*store = ft_strjoin(temp, buff);
		ft_strdel(&temp);
	}
//	printf("no newline: temp = %p\n", temp);
}

static int	ft_yes_newline(char **store, char **line, char *buff, int index)
{
	char	*temp = NULL;
	char	*temp2 = NULL;

	if (*store != NULL)
	{
		temp = ft_strdup(*store);
		temp2 = ft_strsub(buff, 0, index);
		*line = ft_strjoin(temp, temp2);
		ft_strdel(&temp);
		ft_strdel(&temp2);
		ft_strdel(store);
	}
	else
	{
		*store = ft_strsub(buff, 0, index);
		*line = ft_strdup(*store);
		ft_strdel(store);
	}
//	printf("yes newline 0.0: store: = %p\n", *store);
	*store = ft_strsub(buff, (index + 1), (ft_strlen(buff) - (index)));
//	printf("yes newline: temp = %p, temp2 = %p\n", temp, temp2);
	return (1);
}

static int	ft_noread(char **store, char **line, int index)
{
	char	*temp = NULL;

	temp = ft_strdup(*store);
	*line = ft_strsub(*store, 0, index);
	ft_strdel(store);
//	printf("no read 0.0: store: = %p\n", store);
	*store = ft_strsub(temp, (index + 1), (ft_strlen(temp) - (index)));
	ft_strdel(&temp);
//	printf("no read temp = %p\n", temp);
	return (1);
}

static int	ft_save_lines(char **line, char **store)
{
	*line = ft_strdupdel(store);

//	printf("save lines: store: = %p\n", *store);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*store = NULL;
	char		buff[BUFF_SIZE + 1];
	int			index;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	if (store != NULL && (index = ft_check_newline(store)) != -1)
		return (ft_noread(&store, line, index));
	while ((index = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[index] = '\0';
		if (ft_check_newline(buff) == -1)
		{
			ft_no_newline(&store, buff);
			if (index < BUFF_SIZE)
			{
				index = ft_save_lines(line, &store);
				return (index);
			}
		}
		else if ((index = ft_check_newline(buff)) != -1)
			return (ft_yes_newline(&store, line, buff, index));
	}
	if (store != NULL && ft_check_newline(store) == -1)
		return (ft_save_lines(line, &store));
	return (0);
}
