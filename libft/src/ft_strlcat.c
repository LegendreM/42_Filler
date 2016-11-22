/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:59:40 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/09 17:00:08 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t slen;
	size_t dlen;

	j = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen((const char*)dst);
	if (dlen >= size || !size || !dst || !src)
		return (slen + size);
	while (src[j] && (dlen + j) < size - 1)
	{
		dst[dlen + j] = src[j];
		++j;
	}
	dst[dlen + j] = '\0';
	return (slen + dlen);
}
