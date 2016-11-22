/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_subft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:24:33 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:24:40 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		extract_signed_short(const int n)
{
	int	i;

	i = n & SHORT_VALUE_MASK;
	if ((n & SHORT_SIGN_MASK) > 0)
		i = i | SHORT_TO_INT_NEGATIVE_MASK;
	return (i);
}

static	int		extract_signed_char(const int n)
{
	int	i;

	i = n & CHAR_VALUE_MASK;
	if ((n & CHAR_SIGN_MASK) > 0)
		i = i | CHAR_TO_INT_NEGATIVE_MASK;
	return (i);
}

void			ft_d(va_list *ap, t_to_print *print)
{
	intmax_t current;

	current = 0;
	if (print->format->modifier == kNone)
		current = va_arg(*ap, int);
	else if (print->format->modifier == kL)
		current = va_arg(*ap, long);
	else if (print->format->modifier == kH)
		current = extract_signed_short(va_arg(*ap, int));
	else if (print->format->modifier == kJ)
		current = va_arg(*ap, intmax_t);
	else if (print->format->modifier == kZ)
		current = va_arg(*ap, ssize_t);
	else if (print->format->modifier == kLL)
		current = va_arg(*ap, long long);
	else
		current = extract_signed_char(va_arg(*ap, int));
	print->print = ft_litoa(current);
	print->len = ft_strlen(print->print);
}
