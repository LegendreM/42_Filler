/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxlibft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:54:59 by mlegendr          #+#    #+#             */
/*   Updated: 2016/03/21 15:55:02 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXLIBFT_H
# define MLXLIBFT_H
# include <mlx.h>

typedef unsigned char	t_sample_8u;

typedef	struct	s_mlx_image_8u
{
	void		*ptr;
	t_sample_8u	*data;
	int			width;
	int			height;
}				t_mlx_image_8u;

typedef	struct	s_roi
{
	int			width;
	int			height;
	int			x;
	int			y;
}				t_roi;

typedef	struct	s_pixel_8u
{
	t_sample_8u	red;
	t_sample_8u	green;
	t_sample_8u	blue;
	t_sample_8u	alpha;
}				t_pixel_8u;

t_mlx_image_8u	*new_mlx_image_8u(void *mlx_ptr, int width, int height);
t_mlx_image_8u	*new_mlx_xpm_image_8u(void *mlx_ptr, char *filename);
void			free_mlx_image_8u(void *mlx_ptr, t_mlx_image_8u *image);
void			red_8u(t_mlx_image_8u *image, int x, int y, t_sample_8u red);
void			green_8u(t_mlx_image_8u *image, int x, int y,
							t_sample_8u green);
void			blue_8u(t_mlx_image_8u *image, int x, int y, t_sample_8u blue);
void			alpha_8u(t_mlx_image_8u *image, int x, int y,
							t_sample_8u alpha);
void			pixel_8u(t_mlx_image_8u *image, int x, int y,
						t_pixel_8u pixel);
t_pixel_8u		get_pixel_8u(t_mlx_image_8u *image, int x, int y);
t_pixel_8u		new_pixel_8u(t_sample_8u red, t_sample_8u green,
						t_sample_8u blue, t_sample_8u alpha);

#endif
