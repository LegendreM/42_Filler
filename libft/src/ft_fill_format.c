/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:27:40 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:27:46 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_recup_dollar(t_format *format)
{
	format->dollar = ft_atoi(++format->format);
	if (format->dollar == 0)
		ft_error(kSyntax, __FUNCTION__, __LINE__);
}

static void		ft_recup_precision(t_format *format)
{
	char *str;

	str = ft_strchr(format->format, '.');
	format->precision = ft_atoi(++str);
	return ;
}

static void		ft_recup_min_size(t_format *format)
{
	int i;

	i = 0;
	if (format->dollar > 0)
		while (format->format[i++] != '$')
			;
	while (format->format[i] && format->format[i] != '.' &&
		(!ft_isdigit(format->format[i]) || format->format[i] == '0'))
		++i;
	if (ft_isdigit(format->format[i]))
		format->min_size = ft_atoi(&format->format[i]);
	return ;
}

static void		ft_recup_modifier(t_format *format, int nb)
{
	int		len;
	char	c;

	len = (int)ft_strlen(format->format);
	c = format->format[len - nb];
	if (nb == 3)
		format->modifier = (t_modifier)ft_findflag("lh", c) + 5;
	else if (nb == 2)
		format->modifier = (t_modifier)ft_findflag("lhjz", c) + 1;
}

void			ft_fill_format(t_format *format)
{
	int nb;

	nb = 0;
	if (ft_check_dollar(format->format) == 1)
		ft_recup_dollar(format);
	if ((nb = ft_check_points(format->format)) == 1)
		ft_recup_precision(format);
	if (ft_check_sharp(format->format) >= 1)
		format->sharp = 1;
	if (ft_check_zero(format) >= 1)
		format->zero = 1;
	if (ft_check_plus(format->format) >= 1)
		format->plus = 1;
	if (ft_check_minus(format->format) >= 1)
		format->minus = 1;
	ft_recup_min_size(format);
	if ((nb = ft_count_letter(format->format)) > 1)
		ft_recup_modifier(format, nb);
	if (ft_check_space(format->format) >= 1)
		format->space = 1;
}
