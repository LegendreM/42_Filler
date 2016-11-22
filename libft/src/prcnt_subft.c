/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prcnt_subft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:34:28 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:34:30 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prcnt(va_list *ap, t_to_print *print)
{
	(void)ap;
	print->len = 1;
	print->print = ft_strdup("%");
}
