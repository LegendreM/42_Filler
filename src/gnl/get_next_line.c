/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 15:57:25 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/07 10:12:36 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char	*file = NULL;
	char		*tmp;
	int			i;
	int			size;

	i = 0;
	if (file == NULL || ft_strchr((const char *)file, '\n') == NULL)
		if (read_file(fd, &file) == -1)
			return (-1);
	size = ft_strlen(file);
	tmp = file;
	while (*file != '\n' && *file != '\0')
	{
		file++;
		i++;
	}
	*file = '\0';
	*line = ft_strdup(tmp);
	if (size == 0)
		return (0);
	else
	{
		file++;
		file = ft_strdup(file);
		free(tmp);
		return (1);
	}
}

int		read_file(const int fd, char **file)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (*file == NULL)
			*file = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(*file, buf);
			free(*file);
			*file = tmp;
		}
		if (ft_strchr((const char *)*file, '\n') != NULL)
			break ;
	}
	return (0);
}
