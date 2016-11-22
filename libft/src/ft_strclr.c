/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:24:13 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/06 14:44:51 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_strclr(char *s)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (i < len)
		{
			s[i] = '\0';
			++i;
		}
	}
}
