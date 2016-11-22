/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_subft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:34:10 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:34:12 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_octal(uintmax_t n)
{
	const uintmax_t	mask = 7;
	char			*str;

	str = ft_strnew(0);
	while (n > 0)
	{
		ft_strrcharadd(&str, (n & mask) + 48, 1);
		n = (n >> 3);
	}
	return (str);
}

void			ft_o(va_list *ap, t_to_print *print)
{
	uintmax_t current;

	if (print->format->modifier == kNone)
		current = va_arg(*ap, unsigned int);
	else if (print->format->modifier == kL)
		current = va_arg(*ap, unsigned long);
	else if (print->format->modifier == kH)
		current = va_arg(*ap, unsigned int) & 0x0000ffff;
	else if (print->format->modifier == kJ)
		current = va_arg(*ap, uintmax_t);
	else if (print->format->modifier == kZ)
		current = va_arg(*ap, size_t);
	else if (print->format->modifier == kLL)
		current = va_arg(*ap, unsigned long long);
	else
		current = va_arg(*ap, unsigned int) & 0x000000ff;
	print->print = ft_octal(current);
	print->len = ft_strlen(print->print);
	if (ft_strcmp(print->print, "") == 0)
	{
		ft_strrcharadd(&print->print, '0', 1);
		++print->len;
	}
}

void			ft_lo(va_list *ap, t_to_print *print)
{
	unsigned long int current;

	if (print->format->modifier != kNone)
		ft_error(kModifier, __FUNCTION__, __LINE__);
	current = va_arg(*ap, unsigned long int);
	print->print = ft_octal(current);
	print->len = ft_strlen(print->print);
	if (ft_strcmp(print->print, "") == 0)
	{
		ft_strrcharadd(&print->print, '0', 1);
		++print->len;
	}
}
