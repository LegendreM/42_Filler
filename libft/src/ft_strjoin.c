/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:10:34 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/15 10:38:15 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*newstr;

	lens1 = 0;
	lens2 = 0;
	if (s1 && s2)
	{
		lens1 = ft_strlen(s1);
		lens2 = ft_strlen(s2);
		newstr = ft_strnew(lens1 + lens2 + 1);
		if (newstr)
		{
			newstr = ft_strcat(newstr, s1);
			newstr = ft_strcat(newstr, s2);
			return (newstr);
		}
	}
	return (NULL);
}
