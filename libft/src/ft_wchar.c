/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:32:51 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:32:54 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

static	int		ft_wchar_to_char2(wchar_t chr, char *str, int *i)
{
	if (chr <= 0x10FFFF)
	{
		str[(*i)++] = ((chr >> 18) + 0xF0);
		str[(*i)++] = (((chr >> 12) & 0x3F) + 0x80);
		str[(*i)++] = (((chr >> 6) & 0x3F) + 0x80);
		str[(*i)++] = ((chr & 0x3F) + 0x80);
		return (4);
	}
	return (-1);
}

int				ft_wchar_to_char(wchar_t chr, char *str, int *i)
{
	if (chr <= 0x7F)
	{
		str[(*i)++] = chr;
		return (1);
	}
	else if (chr <= 0x7FF)
	{
		str[(*i)++] = ((chr >> 6) + 0xC0);
		str[(*i)++] = ((chr & 0x3F) + 0x80);
		return (2);
	}
	else if (chr <= 0xFFFF)
	{
		str[(*i)++] = ((chr >> 12) + 0xE0);
		str[(*i)++] = (((chr >> 6) & 0x3F) + 0x80);
		str[(*i)++] = ((chr & 0x3F) + 0x80);
		return (3);
	}
	return (ft_wchar_to_char2(chr, str, i));
}

int				ft_wcslen(wchar_t *ws)
{
	wchar_t *p;

	p = ws;
	while (*p)
		p++;
	return (p - ws);
}
