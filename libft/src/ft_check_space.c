/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:27:01 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:27:10 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_space(char *format)
{
	int	i;
	int count;
	int len;

	len = ((int)ft_strlen(format)) - 1;
	count = 0;
	i = 1;
	while (format[i])
	{
		if (format[i] == ' ')
			++count;
		if (i > 1 && format[i] == ' ' && \
			ft_findflag(" $", format[i - 1]) == -1 && count >= 1)
			ft_error(kSyntax, __FUNCTION__, __LINE__);
		++i;
	}
	if (count > 0 && ft_findflag("diD", format[len]) == -1)
		ft_error(kSyntax, __FUNCTION__, __LINE__);
	return (count);
}
