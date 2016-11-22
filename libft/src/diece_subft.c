/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diece_subft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:46:59 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:47:02 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dio(t_to_print *data)
{
	char c;

	c = '0';
	if (ft_strcmp((const char*)data->print, "0") == 0)
		return ;
	ft_strrcharadd(&(data->print), c, 1);
	data->len += 1;
}

void	ft_dix(t_to_print *data)
{
	char c;
	char d;

	d = '0';
	c = 'x';
	if (ft_strcmp((const char*)data->print, "0") == 0)
		return ;
	if (ft_strcmp((const char*)data->print, "") == 0)
		return ;
	ft_strrcharadd(&(data->print), c, 1);
	ft_strrcharadd(&(data->print), d, 1);
	data->len += 2;
}

void	ft_dilx(t_to_print *data)
{
	char c;
	char d;

	d = '0';
	c = 'X';
	if (ft_strcmp((const char*)data->print, "0") == 0)
		return ;
	if (ft_strcmp((const char*)data->print, "") == 0)
		return ;
	ft_strrcharadd(&(data->print), c, 1);
	ft_strrcharadd(&(data->print), d, 1);
	data->len += 2;
}

void	ft_din(t_to_print *data)
{
	char c;
	char d;

	d = '.';
	c = '0';
	if (ft_strcmp((const char*)data->print, "0") == 0)
		return ;
	ft_strcharadd(&(data->print), c, 1);
	ft_strcharadd(&(data->print), c, 2);
	data->len += 2;
}

void	ft_dip(t_to_print *data)
{
	char c;
	char d;

	d = '0';
	c = 'x';
	if (ft_strcmp((const char*)data->print, "") == 0)
		return ;
	ft_strrcharadd(&(data->print), c, 1);
	ft_strrcharadd(&(data->print), d, 1);
	data->len += 2;
}
