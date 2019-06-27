#include "get_next_line.h"
#include <stdio.h>

int		ft_storetoline(char **store, char **line)
{
	int 	len;

	len = 0;
	printf("line check 1, len = %i\n", len);
	if (ft_strchr(*store, '\n') != NULL)
	{
		len = ft_strchr(*store, '\n') - *store;
		printf("line check 2, len = %i\n", len);
		*line = ft_strsub(*store, 0, len);
		printf("line check 3, line = %s\n", *line);
		*store = ft_strchr(*store, '\n') + 1;
		printf("line check 4, store = %s\n", *store);

		if (*store[0] == '\0' && *store != NULL)
	{
			printf("line check 5, store = %s\n", *store);
			free(store);
			printf("line check 6, store = %s\n", *store);

	}
	}
	else if (ft_strchr(*store, '\0') != NULL)
	{
		len = ft_strchr(*store, '\0') - *store;
		printf("line check 7, len = %i\n", len);

		*line = ft_strsub(*store, 0, len);
		ft_strdel(store);
	}
	printf("line check end store = %s\n", *store);

	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*store = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			n;

	n = 0;
	if (fd < 0 || *line == NULL || read(fd, buff, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	if (store != NULL)
		return (ft_storetoline(&store, line)); 
	while((n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n] = '\0';
		printf("check 0, buff = %s\n", buff);
		if (store == NULL)
			store = ft_strnew(1);
//		printf("check 1, store = %s\n", store);
		temp = ft_strjoin(store, buff);
		free(store);
		store = ft_strdupdel(&temp);
//		printf("check 2, temp = %s\n", temp);	
//		ft_strdel(&temp);	
		printf("check 3, store = %s\n", store);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (n < 0)
		return (-1);
	else if (n == 0 && (store == NULL || store[0] == '\0'))
		return (0);
	else if (n > 0)
		return (ft_storetoline(&store, line));
	return (0);
}
