/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:24:51 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:24:54 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sharp(t_to_print *data, int fn)
{
	if (fn == 10)
	{
		ft_dix(data);
	}
	else if (fn == 11)
	{
		ft_dilx(data);
	}
	else if (fn == 6 || fn == 7)
	{
		ft_dio(data);
	}
	else if (fn == 2)
	{
		ft_dip(data);
	}
}

void	ft_min_size(t_to_print *data, size_t size)
{
	size_t len;

	len = data->len;
	if (size > len)
	{
		if (data->format->minus > 0)
		{
			ft_strcharadd(&data->print, ' ', size - len);
			data->len += (int)(size - len);
		}
		else
		{
			ft_strrcharadd(&data->print, ' ', size - len);
			data->len += (int)(size - len);
		}
	}
}

void	ft_zero(t_to_print *data, size_t size)
{
	size_t len;

	len = data->len;
	if (data->print[0] == '-')
	{
		data->print[0] = '0';
		if (size > len)
			ft_strrcharadd(&(data->print), '0', size - len);
		data->print[0] = '-';
	}
	else
	{
		if (size > len)
			ft_strrcharadd(&(data->print), '0', size - len);
	}
	if (size > len)
		data->len += (int)(size - len);
}

void	ft_plus(t_to_print *data)
{
	if (data->print[0] != '-')
	{
		if (data->print[0] == '0' &&
			ft_strlen(data->print) > 1 && data->format->zero > 0)
			data->print[0] = '+';
		else
		{
			ft_strrcharadd(&data->print, '+', 1);
			data->len += 1;
		}
	}
}

void	ft_space(t_to_print *data)
{
	if (data->print[0] != '-')
	{
		if (data->print[0] == '0' &&
			ft_strlen(data->print) > 1 && data->format->zero > 0)
			data->print[0] = ' ';
		else
		{
			ft_strrcharadd(&data->print, ' ', 1);
			data->len += 1;
		}
	}
}
