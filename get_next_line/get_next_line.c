/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:06:55 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/19 16:30:01 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_newline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void		ft_no_newline(char **store, char **line, char *buff)
{
	char	*temp;

	(void)*line;//for now
	if (*store == NULL)
	{
		*store = ft_strdup(buff);
		//*line = ft_strdup(*store);
		//free(*store);
	}
	else
	{
		temp = ft_strdup(*store);
		free(*store); //might cry
		*store = ft_strjoin(temp, buff);
		free(temp);
		//*line = ft_strdup(*store);
		//free(*store);
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

int			get_next_line(const int fd, char **line)
{
	static char	*store = NULL;
	char		buff[BUFF_SIZE + 1];
	int			index;

	buff[BUFF_SIZE] = '\0';
	if (fd < 0 || line == NULL)
		return (-1);
	if (store != NULL && (index = ft_check_newline(store)) != -1)
		return (ft_noread(&store, line, index));
	while ((read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ft_check_newline(buff) == -1)
			ft_no_newline(&store, line, buff);
		else if ((index = ft_check_newline(buff)) != -1)
			return (ft_yes_newline(&store, line, buff, index));
	}
	return (0);
}
