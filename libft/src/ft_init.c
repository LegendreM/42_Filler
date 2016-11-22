/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:28:10 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:28:21 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_init_format(t_format **format)
{
	if (!(*format = (t_format*)malloc(sizeof(t_format))))
		ft_error(kMalloc, __FUNCTION__, __LINE__);
	(*format)->format = ft_strnew(0);
	(*format)->precision = -1;
	(*format)->min_size = 0;
	(*format)->modifier = kNone;
	(*format)->sharp = 0;
	(*format)->zero = 0;
	(*format)->minus = 0;
	(*format)->plus = 0;
	(*format)->dollar = 0;
	(*format)->space = 0;
}

t_tools			*ft_init_tools(void)
{
	t_tools		*tools;

	tools = (t_tools*)malloc(sizeof(t_tools));
	tools->flags = ft_strdup("sSpdDioOuUxXcCb%");
	tools->tab_ft[0] = (ft_s);
	tools->tab_ft[1] = (ft_ls);
	tools->tab_ft[2] = (ft_p);
	tools->tab_ft[3] = (ft_d);
	tools->tab_ft[4] = (ft_ld);
	tools->tab_ft[5] = (ft_d);
	tools->tab_ft[6] = (ft_o);
	tools->tab_ft[7] = (ft_lo);
	tools->tab_ft[8] = (ft_u);
	tools->tab_ft[9] = (ft_lu);
	tools->tab_ft[10] = (ft_x);
	tools->tab_ft[11] = (ft_lx);
	tools->tab_ft[12] = (ft_c);
	tools->tab_ft[13] = (ft_lc);
	tools->tab_ft[14] = (ft_b);
	tools->tab_ft[15] = (ft_prcnt);
	return (tools);
}

t_iterator		*new_arg_iterator(va_list *begin)
{
	t_iterator *new_it;

	if (!(new_it = (t_iterator *)malloc(sizeof(t_iterator))))
		return (NULL);
	if (!(new_it->begin = (va_list *)malloc(sizeof(va_list))))
		return (NULL);
	va_copy(*new_it->begin, *begin);
	if (!(new_it->current = (va_list *)malloc(sizeof(va_list))))
		return (NULL);
	va_copy(*new_it->current, *begin);
	return (new_it);
}
