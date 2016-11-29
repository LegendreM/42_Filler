/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmejia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:22:08 by dmejia            #+#    #+#             */
/*   Updated: 2016/09/05 16:24:04 by dmejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_strjoin_and_free(char *s1, char *s2)
{
	size_t			lens1;
	size_t			lens2;
	char			*newstr;

	lens1 = 0;
	lens2 = 0;
	if (s1 && s2)
	{
		lens1 = ft_strlen(s1);
		lens2 = ft_strlen(s2);
		newstr = ft_strnew(lens1 + lens2 + 1);
		if (newstr)
		{
			newstr = ft_strcat(newstr, s1);
			newstr = ft_strcat(newstr, s2);
			free(s1);
			return (newstr);
		}
	}
	return (NULL);
}

static t_tools		*ft_distrib_fd(int const fd, t_list **list)
{
	t_list			*list_tmp;
	t_tools			*tools;

	list_tmp = *list;
	while (list_tmp)
	{
		tools = (t_tools*)list_tmp->content;
		if (fd == tools->fd)
			return (tools);
		list_tmp = list_tmp->next;
	}
	if (!(list_tmp = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	list_tmp->next = NULL;
	if (!(tools = (t_tools*)ft_memalloc(sizeof(t_tools))))
		return (NULL);
	tools->fd = fd;
	tools->stock = ft_strnew(0);
	list_tmp->content = (t_tools*)tools;
	ft_lstadd(list, list_tmp);
	return (tools);
}

static int			ft_check_stock(t_tools **tools, char **line)
{
	int				i;
	int				len;
	char			*tmp_stock;

	i = 0;
	if ((*tools)->stock != NULL)
	{
		while ((*tools)->stock[i])
		{
			if ((*tools)->stock[i] == '\n')
			{
				tmp_stock = (*tools)->stock;
				*line = ft_strndup((*tools)->stock, i);
				len = (int)ft_strlen((*tools)->stock);
				++i;
				(*tools)->stock = ft_strsub((*tools)->stock, i, len);
				free(tmp_stock);
				return (1);
			}
			++i;
		}
	}
	return (0);
}

static int			ft_reader(t_tools **tools, char **line)
{
	char			*buf;
	int				lu;
	int				ok;

	ok = 0;
	lu = 0;
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((lu = read((*tools)->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[lu] = '\0';
		(*tools)->stock = ft_strjoin_and_free((*tools)->stock, buf);
		if (ft_check_stock(tools, *&line) && (ok = 1))
			break ;
		ok = 2;
	}
	ft_strdel(&buf);
	if (lu < 0)
		return (-1);
	if (ok == 2)
	{
		lu = ft_strlen((*tools)->stock);
		*line = ft_strndup((*tools)->stock, lu);
		return (1);
	}
	return (ok);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	t_tools			*tools;
	int				ret;

	ret = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(tools = ft_distrib_fd(fd, &list)))
		return (-1);
	if ((ret = ft_check_stock(&tools, &*line)))
		return (ret);
	ret = ft_reader(&tools, &*line);
	return (ret);
}
