/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:08:35 by mlegendr          #+#    #+#             */
/*   Updated: 2014/12/22 23:15:14 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strradd(char **dst, char *src)
{
	char *str;

	str = ft_strjoin(src, *dst);
	ft_strdel(dst);
	*dst = str;
}
