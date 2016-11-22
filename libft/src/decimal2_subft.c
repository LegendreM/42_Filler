/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal2_subft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:24:14 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:24:22 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_ld(va_list *ap, t_to_print *print)
{
	long int current;

	if (print->format->modifier != kNone)
		ft_error(kModifier, __FUNCTION__, __LINE__);
	current = va_arg(*ap, long int);
	print->print = ft_litoa(current);
	print->len = ft_strlen(print->print);
}

void			ft_u(va_list *ap, t_to_print *print)
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
	print->print = ft_ullitoa(current);
	print->len = ft_strlen(print->print);
}

void			ft_lu(va_list *ap, t_to_print *print)
{
	unsigned long int current;

	if (print->format->modifier != kNone)
		ft_error(kModifier, __FUNCTION__, __LINE__);
	current = va_arg(*ap, unsigned long int);
	print->print = ft_ullitoa(current);
	print->len = ft_strlen(print->print);
}
