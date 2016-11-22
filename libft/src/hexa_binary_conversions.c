/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_binary_conversions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:33:05 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:33:29 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bases.h"

static	t_base_data	*init_base_data(t_base enum_base)
{
	t_base_data *base_data;

	if (!(base_data = (t_base_data *)ft_memalloc(sizeof(t_base_data))))
		return (NULL);
	if (enum_base == kHexadecimal_X || enum_base == kHexadecimal_x)
	{
		base_data->base = 16;
		base_data->bits_per_base = 4;
	}
	else
	{
		base_data->base = 2;
		base_data->bits_per_base = 1;
	}
	if (enum_base == kHexadecimal_x)
		base_data->base_values = ft_strdup("0123456789abcdef");
	else
		base_data->base_values = ft_strdup("0123456789ABCDEF");
	base_data->bases_per_byte = 8 / base_data->bits_per_base;
	base_data->mask = (base_data->base - 1) << (8 - base_data->bits_per_base);
	return (base_data);
}

static	char		*convert_base_to_ascii
	(const char *base_values, const t_byte *values, size_t size)
{
	char		*str;
	size_t		i;

	str = ft_strnew(size + 1);
	i = 0;
	while (i < size)
	{
		str[i] = base_values[values[i]];
		++i;
	}
	return (str);
}

static	char		*format_byte_in_base(t_byte byte, const t_base_data *base)
{
	t_byte	*values;
	char	*str;
	size_t	i;

	values = (t_byte *)ft_memalloc(base->bases_per_byte);
	i = 0;
	while (i < base->bases_per_byte)
	{
		values[i] = (byte & base->mask) >> (8 - base->bits_per_base);
		byte = byte << base->bits_per_base;
		++i;
	}
	str = convert_base_to_ascii(base->base_values,
								values, base->bases_per_byte);
	ft_memdel((void**)&values);
	return (str);
}

void				convert_to_base
	(va_list *ap, t_to_print *print, t_base eb, size_t size)
{
	const t_base_data	*base = init_base_data(eb);
	uintmax_t			n;
	t_byte				*b;
	char				*tmp;
	int					i;

	print->print = ft_strnew(size * base->bases_per_byte);
	n = va_arg(*ap, uintmax_t);
	b = (t_byte *)&n;
	i = size;
	while (--i >= 0)
	{
		tmp = format_byte_in_base(b[i], base);
		ft_strcat(print->print, tmp);
		print->len = ft_strlen(print->print);
		ft_strdel(&tmp);
	}
}
