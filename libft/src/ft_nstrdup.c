/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 22:33:57 by mlegendr          #+#    #+#             */
/*   Updated: 2015/01/02 11:40:40 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_nstrdup(const char *s1, size_t n)
{
	char	*dup;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (s1)
		len = ft_strlen(s1);
	if (len == n)
		return (NULL);
	dup = NULL;
	if (s1 && (len >= n))
	{
		if ((dup = (char*)malloc(sizeof(char) * (len - n + 1))))
		{
			len = len - n;
			while (i <= len)
			{
				dup[i] = s1[n];
				++n;
				++i;
			}
		}
	}
	return (dup);
}
