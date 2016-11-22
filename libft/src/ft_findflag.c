/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:27:58 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:28:02 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findflag(const char *s, char c)
{
	size_t	i;
	int		flag;

	flag = -1;
	i = ft_strlen(s);
	if (!c)
		return (flag);
	while (i != 0 && s[i] != c)
		--i;
	if (s[i] == c)
		flag = i;
	return (flag);
}
