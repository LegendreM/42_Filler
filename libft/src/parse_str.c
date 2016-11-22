/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:34:19 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:34:21 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pourcent(char *format, t_list **lst)
{
	int			j;
	t_to_print	to_print;

	j = 1;
	if (format[j] == 0)
		ft_error(kSyntax, __FUNCTION__, __LINE__);
	while (format[j] && ft_findflag("sSpdDioOuUxXcCb%", format[j]) == -1)
		++j;
	if (format[j])
		++j;
	ft_init_format(&to_print.format);
	to_print.format->format = ft_strndup(format, j);
	ft_check_format_error(to_print.format->format);
	ft_fill_format(to_print.format);
	to_print.print = ft_strnew(0);
	to_print.len = 0;
	ft_lstadd(lst, ft_lstnew((void *)&to_print, sizeof(t_to_print)));
	return (j);
}

int		ft_basicstring(char *format, t_list **lst)
{
	int			j;
	t_to_print	to_print;

	j = 0;
	while (format[j] && format[j] != '%')
		++j;
	to_print.print = ft_strndup(format, j);
	to_print.len = j;
	to_print.format = NULL;
	ft_lstadd(lst, ft_lstnew((void *)&to_print, sizeof(t_to_print)));
	return (j);
}
