/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bases.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:41:06 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:41:09 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BASES_H
# define FT_PRINTF_BASES_H
# include <string.h>
# include <stdarg.h>

typedef unsigned char	t_byte;

typedef enum	e_base
{
	kHexadecimal_x,
	kHexadecimal_X,
	kBinary
}				t_base;

typedef struct	s_base_data
{
	char		*base_values;
	t_byte		mask;
	size_t		base;
	size_t		bits_per_base;
	size_t		bases_per_byte;
}				t_base_data;

void			convert_to_base
				(va_list *ap, t_to_print *print, t_base eb, size_t size);
#endif
