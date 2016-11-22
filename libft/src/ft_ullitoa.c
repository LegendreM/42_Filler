/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:32:40 by mlegendr          #+#    #+#             */
/*   Updated: 2016/10/25 15:32:43 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

static unsigned long long int	ft_ullintlen(unsigned long long int n)
{
	unsigned long long int		len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char							*ft_ullitoa(unsigned long long int n)
{
	char						*strnew;
	unsigned long long int		len;

	if (n == 0)
	{
		if (!(strnew = ft_strnew(1)))
			return (NULL);
		strnew[0] = '0';
		return (strnew);
	}
	len = ft_ullintlen(n);
	if (!(strnew = ft_strnew(len)))
		return (NULL);
	len -= 1;
	while (n > 0)
	{
		strnew[len] = (n % 10) + 48;
		n /= 10;
		--len;
	}
	return (strnew);
}
