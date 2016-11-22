/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_binary_subft.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:33:44 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:34:02 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bases.h"

static	size_t	determine_size(t_modifier modifier)
{
	if (modifier == kL)
		return (sizeof(unsigned long));
	else if (modifier == kH)
		return (sizeof(unsigned short));
	else if (modifier == kJ)
		return (sizeof(uintmax_t));
	else if (modifier == kZ)
		return (sizeof(size_t));
	else if (modifier == kLL)
		return (sizeof(unsigned long long));
	else if (modifier == kHH)
		return (sizeof(unsigned char));
	return (sizeof(unsigned int));
}

void			ft_x(va_list *ap, t_to_print *print)
{
	size_t size;

	size = determine_size(print->format->modifier);
	convert_to_base(ap, print, kHexadecimal_x, size);
	trim_zero(&(print->print));
	print->len = ft_strlen(print->print);
	if (ft_strcmp(print->print, "") == 0)
	{
		ft_strrcharadd(&print->print, '0', 1);
		print->len += 1;
	}
	return ;
}

void			ft_lx(va_list *ap, t_to_print *print)
{
	size_t size;

	size = determine_size(print->format->modifier);
	convert_to_base(ap, print, kHexadecimal_X, size);
	trim_zero(&(print->print));
	print->len = ft_strlen(print->print);
	if (ft_strcmp(print->print, "") == 0)
	{
		ft_strrcharadd(&print->print, '0', 1);
		print->len += 1;
	}
	return ;
}

void			ft_b(va_list *ap, t_to_print *print)
{
	size_t size;

	size = determine_size(print->format->modifier);
	convert_to_base(ap, print, kBinary, size);
	return ;
}

void			ft_p(va_list *ap, t_to_print *print)
{
	print->format->modifier = kL;
	print->format->sharp = 1;
	return (ft_x(ap, print));
}
