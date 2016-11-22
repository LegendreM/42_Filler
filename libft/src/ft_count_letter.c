/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:27:28 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:27:31 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_letter(char *format)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (ft_is_valid_alpha(format[i]))
			++count;
		++i;
	}
	return (count);
}
