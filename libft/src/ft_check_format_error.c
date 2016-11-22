/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:26:42 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:26:45 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_format_error(char *format)
{
	int	i;
	int nbc;

	i = 0;
	ft_authorized_char(format);
	if ((nbc = ft_count_letter(format)) > 3)
		ft_error(kSyntax, __FUNCTION__, __LINE__);
	ft_check_letter(format, nbc);
	if (ft_check_points(format) >= 2)
		ft_error(kSyntax, __FUNCTION__, __LINE__);
	ft_check_sharp(format);
	ft_check_plus(format);
	ft_check_minus(format);
	if (ft_check_dollar(format) >= 2)
		ft_error(kSyntax, __FUNCTION__, __LINE__);
	return ;
}
