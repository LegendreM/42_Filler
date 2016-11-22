/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:18:47 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/07 11:35:12 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;
	size_t	len;

	i = 0;
	len = 0;
	str = NULL;
	if (s)
	{
		len = ft_strlen(s);
		if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			str[i] = f(s[i]);
			++i;
		}
		str[i] = '\0';
	}
	return (str);
}
