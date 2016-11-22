/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_authorized_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:25:33 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:25:36 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_authorized_char(char *f)
{
	int i;

	i = 0;
	while (f[i])
	{
		if (ft_findflag("sSpdDioOuUxXcCb$#.1234567890 +-lhjz%", f[i]) == -1)
		{
			ft_error(kSyntax, __FUNCTION__, __LINE__);
		}
		++i;
	}
	return ;
}
