/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 17:00:13 by mlegendr          #+#    #+#             */
/*   Updated: 2014/12/08 17:00:18 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			return_free(int r, char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (r);
}

static int			ft_read(t_read *elem, int const fd)
{
	size_t		ret;
	char		*buf;
	char		*str;
	char		*stmp;

	str = NULL;
	elem->fd = fd;
	elem->next = NULL;
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if ((int)ret < 0)
			return (return_free(0, str, buf));
		buf[ret] = 0;
		if (ft_strlen(buf) != ret)
			return (return_free(0, str, buf));
		if (!(stmp = ft_strjoin(str, buf)))
			return (return_free(0, str, buf));
		free(str);
		str = stmp;
	}
	free(buf);
	elem->read = str;
	return ((elem->read_cpy = elem->read) ? 1 : 1);
}

static t_read		*ft_unread_fd(t_read **lst, int fd)
{
	t_read		*cpy;

	cpy = (*lst);
	while (cpy)
	{
		if (cpy->fd == fd)
			return (cpy);
		cpy = cpy->next;
	}
	if (!(cpy = (t_read*)malloc(sizeof(t_read))))
		return (NULL);
	if (!(ft_read(cpy, fd)))
		return (NULL);
	cpy->next = *lst;
	(*lst) = cpy;
	return (cpy);
}

static int			ft_line(t_read *elem, char **line)
{
	size_t		i;
	char		*str;
	size_t		len;

	i = 0;
	len = 0;
	if (!elem->read_cpy)
		return (0);
	if (!(str = elem->read) && ft_strlen(elem->read_cpy))
		return (-1);
	if (*str == 0)
		return (0);
	while (str[len] != 0 && str[len] != '\n')
		len++;
	if (!((*line) = (char*)malloc(sizeof(char) * (len + 1))))
		return (-1);
	while ((*str) != '\0' && (*str) != '\n')
		(*line)[i++] = *str++;
	(*line)[i] = 0;
	elem->read = (elem->read) + i + 1;
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_read		**lst = NULL;
	t_read				*tmp;
	int					res;

	if (*line)
		free(*line);
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!lst)
	{
		if (!(lst = (t_read**)malloc(sizeof(lst))))
			return (-1);
		*lst = NULL;
	}
	if (!(tmp = ft_unread_fd(lst, fd)))
		return (-1);
	if ((res = ft_line(tmp, line)) == 0)
	{
		tmp->read = NULL;
		if (tmp->read_cpy)
			free(tmp->read_cpy);
	}
	return (res);
}
