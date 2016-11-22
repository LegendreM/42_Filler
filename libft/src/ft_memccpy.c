/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:43:50 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/09 14:00:38 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;
	size_t				i;
	unsigned char		x;

	i = 0;
	x = (unsigned char)c;
	tmp_src = (const unsigned char*)src;
	tmp_dst = (unsigned char*)dst;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_dst[i] == x)
		{
			tmp_dst = &tmp_dst[++i];
			return (tmp_dst);
		}
		++i;
	}
	return (NULL);
}
