/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:34:41 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:34:44 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	trim_zero(char **str)
{
	char *s1;
	char *s2;

	s1 = *str;
	while (*s1 && *s1 == '0')
		++s1;
	if (ft_strcmp(s1, "") == 0)
		s2 = ft_strdup("0");
	else
		s2 = ft_strdup(s1);
	ft_strdel(str);
	*str = s2;
}
