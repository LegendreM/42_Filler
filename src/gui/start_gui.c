/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_gui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 09:35:12 by jle-mene          #+#    #+#             */
/*   Updated: 2017/01/06 11:32:31 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		key_press(int keycode, t_env *env)
{
	(void)keycode;
	(void)env;
	if (keycode == 53)
		exit(0);
	return (0);
}

static int		key_release(int keycode, t_env *env)
{
	(void)keycode;
	(void)env;
	return (0);
}

static t_params	*init_params(t_params *params)
{
	if ((params = (t_params *)malloc(sizeof(t_params))) == NULL)
	{
		ft_putendl_fd("CANNOT MALLLOC IN INIT", 2);
		return (NULL);
	}
	params->game_board = NULL;
	params->game_piece = NULL;
	params->game_piece_min = NULL;
	params->player[0] = '\0';
	params->player[1] = '\0';
	params->player[2] = '\0';
	params->count_line = 0;
	return (params);
}

static int		init_env(t_env *env, t_mlx_env *mlx)
{
	env->params = init_params(NULL);
	if (env->params == NULL)
		return (1);
	env->mlx = mlx;
	env->win_img = new_mlx_image_8u(
					env->mlx->ptr, env->mlx->win_width, env->mlx->win_height);
	return (0);
}

int				start_gui(void)
{
	t_mlx_env		mlx;
	t_env			env;

	mlx.win_width = 2000;
	mlx.win_height = 1200;
	if (!(mlx.ptr = mlx_init()))
		return (EXIT_FAILURE);
	if (!(mlx.win = mlx_new_window(mlx.ptr,
		mlx.win_width, mlx.win_height, "filler")))
		return (EXIT_FAILURE);
	if (init_env(&env, &mlx) != 0)
		return (EXIT_FAILURE);
	mlx_hook(env.mlx->win, KEYPRESS, KEYPRESSMASK, key_press, &env);
	mlx_hook(env.mlx->win, KEYRELEASE, KEYRELEASEMASK, key_release, &env);
	mlx_hook(env.mlx->win, REDCROSS, REDCROSSMASK, red_cross, 0);
	mlx_loop_hook(env.mlx->ptr, loop_hook, &env);
	mlx_loop(env.mlx->ptr);
	return (EXIT_SUCCESS);
}
