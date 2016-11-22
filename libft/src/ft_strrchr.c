/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:19:32 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/07 17:21:20 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = NULL;
	i = ft_strlen(s);
	while (i != 0 && s[i] != (char)c)
		--i;
	if (s[i] == (char)c)
		str = (char*)&s[i];
	return (str);
}
