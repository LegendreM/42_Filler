/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:31:41 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:31:44 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_error(t_error error, const char *fname, const int line)
{
	if (error == kSyntax)
		ft_putstr_fd("Syntax error : in ", 2);
	if (error == kMalloc)
		ft_putstr_fd("Malloc error : in ", 2);
	if (error == kModifier)
		ft_putstr_fd("Modifier error : in ", 2);
	if (error == kVar)
		ft_putstr_fd("Variable error : in ", 2);
	if (error == kNull)
		ft_putstr_fd("Null error : in ", 2);
	ft_putstr_fd(fname, 2);
	ft_putstr_fd(" at line ", 2);
	ft_putnbr_fd(line, 2);
	ft_putchar_fd('\n', 2);
	exit(-1);
	return ;
}

int		ft_printlst(t_list *lst)
{
	int i;
	int len;

	i = 0;
	if (!lst)
		return (0);
	i += ft_printlst(lst->next);
	len = ((t_to_print*)lst->content)->len;
	write(1, ((t_to_print*)lst->content)->print, len);
	i += ((t_to_print*)lst->content)->len;
	return (i);
}

void	ft_del_list(t_list **lst)
{
	t_to_print *tmp;

	if (!*lst)
		return ;
	ft_del_list(&(*lst)->next);
	tmp = (t_to_print*)(*lst)->content;
	ft_memdel((void**)&tmp->format);
	ft_strdel(&tmp->print);
	ft_memdel((void**)&(*lst)->content);
	ft_memdel((void**)lst);
	return ;
}

int		ft_printf(char *format, ...)
{
	va_list		ap;
	t_iterator	*it;
	t_list		*lst;
	int			ret;

	ret = 0;
	va_start(ap, format);
	it = new_arg_iterator(&ap);
	lst = ft_parse(format, it);
	ret += ft_printlst(lst);
	ft_del_list(&lst);
	return (ret);
}
