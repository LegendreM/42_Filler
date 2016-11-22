/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_alpha.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:28:49 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:28:52 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_valid_alpha(int c)
{
	if (!ft_isalpha(c))
		return (0);
	if (ft_findflag("sSpdDioOuUxXcCblzjh", c) != -1)
		return (1);
	ft_error(kSyntax, __FUNCTION__, __LINE__);
	return (0);
}
