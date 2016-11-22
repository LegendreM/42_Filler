/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:31:22 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:31:29 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_precision2(t_to_print *data, int size, char **str, int len)
{
	if (size >= len)
	{
		if (data->print[0] == '-')
		{
			data->print[0] = '0';
			ft_strrcharadd(&data->print, '0', size - len);
			ft_strrcharadd(&data->print, '-', 1);
			data->len += size - len + 1;
		}
		else
		{
			ft_strrcharadd(&data->print, '0', size - len);
			data->len += size - len;
		}
	}
	else if (size == 0 && data->print[0] == '0' && len == 1)
	{
		data->print = ft_strdup("");
		data->len = 0;
		ft_strdel(&(*str));
	}
}

void		ft_precision(t_to_print *data, int size)
{
	int			len;
	char		*str;
	int			i;

	i = 1;
	str = data->print;
	len = (int)ft_strlen(data->print);
	while (data->format->format[i])
	{
		if (ft_findflag("sSpdDioOuUxXcCb$#.1234567890 +-lhjz", \
			data->format->format[i]) == -1)
			return ;
		++i;
	}
	if (ft_findflag(data->format->format, 's') != -1 && size != -1)
	{
		if (len >= size)
		{
			data->len = size;
		}
		data->print = ft_strndup((const char*)str, size);
		ft_strdel(&str);
	}
	else
		ft_precision2(data, size, &str, len);
}
