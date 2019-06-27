/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 08:28:55 by vesingh           #+#    #+#             */
/*   Updated: 2019/06/27 13:17:12 by vesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_storetoline(char **store, char **line)
{
	int	len;
	char *temp;
	
	if (ft_strchr(*store, '\n'))
	{
		len = ft_strchr(*store, '\n') - *store;
		*line = ft_strsub(*store, 0, len);
		temp = ft_strchr(*store, '\n') + 1;
		temp = ft_strdup(temp);
		//ft_putendl(temp);
		//temp = ft_strsub(*store, len + 1, ft_strlen(*store) - len);
		//printf("temp = %s\n", temp);
		//*store = ft_strchr(*store, '\n') + 1;
		ft_strdel(store);
		*store = ft_strdupdel(&temp);
		//sleep(1);
		//printf("line = %s\t store = %s\n", *line, *store);
		//sleep(1);
		if (*store[0] == '\0')
			ft_strdel(store);
			//*store = ft_strnew(0);
	}
	else if (ft_strchr(*store, '\0'))
	{
	//	len = ft_strchr(*store, '\0') - *store;
		*line = ft_strdupdel(store);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*store = NULL;
	char		buff[BUFF_SIZE + 1];
//	char		*temp;
	int			n;

	if (!store)
		store = ft_strnew(0);
	if (fd < 0 || line == NULL)
		return (-1);
	while ((n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n] = '\0';
		store = ft_strjoinfree(store, buff);
//		printf("buff = %s\n", buff);
		//if (store == NULL)
		//	store = ft_strnew(0);
	//	temp = ft_strjoin(store, buff);
		//printf("temp= %s\n", temp);
		//free(store);
		//if (store != NULL)
		//	ft_strdel(&store);
	//	store = ft_strdupdel(&temp);
		//printf("store = %s\n", store);
		if (ft_strchr(store, '\n'))
			break ; 
	}
	if (n < 0)
		return (-1);
	else if (n == 0 && (store == NULL || store[0] == '\0'))
		return (0);
	else 
		return(ft_storetoline(&store, line));
	return (0);
}
