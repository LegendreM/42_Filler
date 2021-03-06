/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:19:19 by jle-mene          #+#    #+#             */
/*   Updated: 2016/12/07 15:59:13 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	play(t_coord orig, int y, int x)
{
	ft_putnbr_fd(y + orig.y, 1);
	write(1, " ", 1);
	ft_putnbr_fd(x + orig.x, 1);
	write(1, "\n", 1);
	return ;
}
