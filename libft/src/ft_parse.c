/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:30:28 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:30:32 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	va_list		*get_index(int index, va_list *begin)
{
	int		i;
	va_list	*tmp;

	if (!(tmp = (va_list*)malloc(sizeof(va_list))))
		return (NULL);
	va_copy(*tmp, *begin);
	i = 0;
	while (i < index)
	{
		va_arg(*tmp, void*);
		++i;
	}
	return (tmp);
}

static	void		ft_ajust(t_to_print *data)
{
	int len;

	if (!(len = (int)ft_strlen(data->format->format)))
		len = 1;
	if (ft_findflag("sS", data->format->format[len - 1]) != -1)
		return ;
	if (data->format->precision > 0 && data->format->min_size > 0)
		data->format->zero = 0;
	else if (data->format->precision > 0 && data->format->min_size == 0 \
		&& data->format->zero > 0)
	{
		data->format->min_size = data->format->precision;
		data->format->precision = -1;
	}
}

static	void		ft_apply_format(t_to_print *data, int fn)
{
	int ko;

	ft_ajust(data);
	if ((ko = 0) && ft_strcmp((const char*)data->print, "0") == 0)
		ko = 1;
	ft_precision(data, (data->format->precision));
	if (data->format->min_size > 0 && data->format->zero == 1)
	{
		if ((data->format->sharp > 0) && (fn == 2 || fn == 10 || fn == 11) \
			&& !ko)
			ft_zero(data, (size_t)(data->format->min_size - 2));
		else if (fn == 6 || fn == 7 || fn == 2 || fn == 10 \
				|| fn == 11 || fn == 3 || fn == 4 || fn == 5 \
				|| fn == 8 || fn == 9 || fn == 14 || ko)
			ft_zero(data, (size_t)(data->format->min_size));
	}
	if (data->format->sharp > 0)
		ft_sharp(data, fn);
	if (data->format->plus > 0)
		ft_plus(data);
	if (data->format->space > 0)
		ft_space(data);
	if (data->format->min_size > 0 && data->format->zero == 0)
		ft_min_size(data, (size_t)(data->format->min_size));
}

static	void		ft_parse_format(t_list *lst, t_iterator *it)
{
	int			i;
	char		*str;
	t_tools		*tools;
	int			len;
	va_list		*va_i;

	va_i = NULL;
	tools = ft_init_tools();
	str = ((t_to_print*)lst->content)->format->format;
	len = (int)ft_strlen(str) - 1;
	i = ft_findflag((const char*)tools->flags, str[len]);
	if (((t_to_print*)lst->content)->format->dollar > 0)
	{
		va_i = get_index(((t_to_print*)lst->content)->\
			format->dollar - 1, it->begin);
		if (i != -1)
			tools->tab_ft[i](va_i, (t_to_print*)lst->content);
	}
	else
	{
		if (i != -1)
			tools->tab_ft[i](it->current, (t_to_print*)lst->content);
	}
	ft_apply_format((t_to_print*)lst->content, i);
}

t_list				*ft_parse(char *format, t_iterator *it)
{
	int			i;
	t_list		*lst;

	lst = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			i += ft_basicstring(&format[i], &lst);
		}
		else
		{
			i += ft_pourcent(&format[i], &lst);
			ft_parse_format(lst, it);
		}
	}
	return (lst);
}
