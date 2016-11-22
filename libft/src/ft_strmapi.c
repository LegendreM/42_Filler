/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:01:47 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/06 14:48:42 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	unsigned int	len;

	i = 0;
	len = 0;
	str = NULL;
	if (s)
	{
		len = (unsigned int)ft_strlen(s);
		if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			str[i] = f(i, s[i]);
			++i;
		}
		str[i] = '\0';
	}
	return (str);
}
