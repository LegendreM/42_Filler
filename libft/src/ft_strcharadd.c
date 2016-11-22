/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:08:35 by mlegendr          #+#    #+#             */
/*   Updated: 2014/12/22 23:15:14 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcharadd(char **dst, char c, size_t n)
{
	char *str;

	str = ft_strnew(n);
	ft_strnfill(str, c, n);
	ft_stradd(dst, str);
}
