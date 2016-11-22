/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_subft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:23:40 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:24:03 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <stdlib.h>

void	ft_c(va_list *ap, t_to_print *print)
{
	char	c;

	if (print->format->modifier == kL)
	{
		print->format->modifier = kNone;
		return (ft_lc(ap, print));
	}
	else if (print->format->modifier != kNone)
		ft_error(kModifier, __FUNCTION__, __LINE__);
	c = (char)va_arg(*ap, int);
	if (!(print->print = ft_strnew(sizeof(char))))
		ft_error(kMalloc, __FUNCTION__, __LINE__);
	print->print[0] = c;
	print->len = 1;
	return ;
}

void	ft_lc(va_list *ap, t_to_print *print)
{
	wchar_t	ws;
	int		i;

	if (print->format->modifier != kNone)
		ft_error(kModifier, __FUNCTION__, __LINE__);
	i = 0;
	ws = va_arg(*ap, wchar_t);
	if (!(print->print = ft_strnew(sizeof(wchar_t))))
		ft_error(kMalloc, __FUNCTION__, __LINE__);
	print->len += ft_wchar_to_char(ws, print->print, &i);
	return ;
}

void	ft_s(va_list *ap, t_to_print *print)
{
	char	*str;
	int		len;

	if (print->format->modifier == kL)
	{
		print->format->modifier = kNone;
		return (ft_ls(ap, print));
	}
	else if (print->format->modifier != kNone)
		ft_error(kModifier, __FUNCTION__, __LINE__);
	str = va_arg(*ap, char*);
	if (str)
	{
		len = (int)ft_strlen(str);
		print->len += len;
		if (!(print->print = ft_strdup((const char*)str)))
			ft_error(kMalloc, __FUNCTION__, __LINE__);
	}
	else
	{
		if (!(print->print = ft_strdup("(null)")))
			ft_error(kMalloc, __FUNCTION__, __LINE__);
		print->len = 6;
	}
	return ;
}

void	ft_ls(va_list *ap, t_to_print *print)
{
	wchar_t	*ws;
	int		wslen;
	int		i;
	wchar_t chr;

	if (print->format->modifier != kNone)
		ft_error(kModifier, __FUNCTION__, __LINE__);
	i = 0;
	ws = va_arg(*ap, wchar_t*);
	if (!ws)
		ft_error(kNull, __FUNCTION__, __LINE__);
	chr = *ws;
	wslen = ft_wcslen(ws);
	if (!(print->print = ft_strnew(sizeof(wchar_t) * wslen)))
		ft_error(kMalloc, __FUNCTION__, __LINE__);
	while (*ws)
	{
		chr = *ws;
		print->len += ft_wchar_to_char(chr, print->print, &i);
		ws++;
	}
	return ;
}
