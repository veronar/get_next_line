/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:06:55 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/24 16:33:35 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_no_newline(char **store, char *buff)
{
	char	*temp;

	if (*store == NULL)
	{
		*store = ft_strdup(buff);
	}
	else
	{
		temp = ft_strdup(*store);
		free(*store);
		*store = ft_strjoin(temp, buff);
		free(temp);
	}
}

static int	ft_yes_newline(char **store, char **line, char *buff, int index)
{
	char	*temp;
	char	*temp2;

	if (*store != NULL)
	{
		temp = ft_strdup(*store);
		temp2 = ft_strsub(buff, 0, index);
		*line = ft_strjoin(temp, temp2);
		free(temp);
		free(temp2);
		free(*store);
	}
	else
	{
		*store = ft_strsub(buff, 0, index);
		*line = ft_strdup(*store);
		free(*store);
	}
	*store = ft_strsub(buff, (index + 1), (ft_strlen(buff) - (index)));
	return (1);
}

static int	ft_noread(char **store, char **line, int index)
{
	char	*temp;

	temp = ft_strdup(*store);
	*line = ft_strsub(*store, 0, index);
	free(*store);
	*store = ft_strsub(temp, (index + 1), (ft_strlen(temp) - (index)));
	free(temp);
	return (1);
}

static int	ft_save_lines(char **line, char **store)
{
	*line = ft_strdupdel(store);
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
				return (ft_save_lines(line, &store));
		}
		else if ((index = ft_check_newline(buff)) != -1)
			return (ft_yes_newline(&store, line, buff, index));
	}
	if (store != NULL && ft_check_newline(store) == -1)
		return (ft_save_lines(line, &store));
	return (0);
}
