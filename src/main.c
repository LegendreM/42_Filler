/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:19:24 by jle-mene          #+#    #+#             */
/*   Updated: 2016/11/30 11:19:51 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_coord		to_play;
	t_params 	*params;

	params = NULL;
	while (1)
	{
		params = parser(params);
		if (ai_launch(params, &to_play))
		{
			play(to_play.y, to_play.x);
		}
	}
	return (0);
}
