/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:26:27 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:26:31 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_dollar(char *format)
{
	int	i;
	int count;
	int tmp;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '$')
		{
			++count;
			tmp = i;
			if (tmp == 1)
				ft_error(kSyntax, __FUNCTION__, __LINE__);
			while (--tmp != 0)
				if ((!ft_isdigit(format[tmp]) && \
					ft_findflag("%", format[tmp]) == -1))
				{
					ft_error(kSyntax, __FUNCTION__, __LINE__);
				}
		}
		++i;
	}
	return (count);
}
