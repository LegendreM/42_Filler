/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:55:01 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/09 14:15:05 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	str = NULL;
	len = ft_strlen(s1);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str)
		ft_strcpy(str, s1);
	return (str);
}
