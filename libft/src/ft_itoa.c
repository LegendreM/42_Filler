/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 09:42:37 by mlegendr          #+#    #+#             */
/*   Updated: 2014/11/09 19:11:28 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static	int		ft_intleng(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		++len;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*strnew;
	size_t	len;

	if (n == 0)
	{
		if (!(strnew = ft_strnew(1)))
			return (NULL);
		strnew[0] = '0';
		return (strnew);
	}
	len = ft_intleng(n);
	if (!(strnew = ft_strnew(len)))
		return (NULL);
	len -= 1;
	if (n > 0)
		n *= -1;
	if (n < 0)
		strnew[0] = '-';
	while (n < 0)
	{
		strnew[len] = -(n % 10) + 48;
		n /= 10;
		--len;
	}
	return (strnew);
}
