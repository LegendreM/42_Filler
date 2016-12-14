/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxlibft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:54:59 by mlegendr          #+#    #+#             */
/*   Updated: 2016/12/13 09:23:09 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXLIBFT_H

# define MLXLIBFT_H
# define KEYPRESSMASK	(1L<<0)
# define KEYRELEASEMASK	(1L<<1)
# define REDCROSSMASK	(1L<<17)
# define KEYPRESS		2
# define KEYRELEASE		3
# define REDCROSS		17
# define RED_PX			create_pixel_8u(0xff, 0x00, 0x00, 0x00)
# define GREEN_PX		create_pixel_8u(0x00, 0xff, 0x00, 0x00)
# define BLUE_PX		create_pixel_8u(0x00, 0x00, 0xff, 0x00)
# define LIGHT_RED_PX	create_pixel_8u(0xff, 0x50, 0x50, 0x00)
# define LIGHT_GREEN_PX	create_pixel_8u(0x50, 0xff, 0x50, 0x00)
# define LIGHT_BLUE_PX	create_pixel_8u(0x50, 0x50, 0xff, 0x00)

typedef unsigned char	t_sample_8u;
typedef unsigned int	t_color_8u;

typedef struct	s_mlx_env
{
	void		*ptr;
	void		*win;
	int			win_width;
	int			win_height;
}				t_mlx_env;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

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
	t_sample_8u	blue;
	t_sample_8u	green;
	t_sample_8u	red;
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
t_pixel_8u		create_pixel_8u(t_sample_8u red, t_sample_8u green,
						t_sample_8u blue, t_sample_8u alpha);
int				draw_square(t_mlx_image_8u *dst,
						const t_roi square, const t_pixel_8u pixel);
t_roi			create_roi(int x, int y, int width, int height);
int				red_cross(int r);
int				clear_image_8u(t_mlx_image_8u *image, const t_pixel_8u pixel);
void			draw_rack(
				t_mlx_image_8u *dst,
				const t_roi roi,
				const t_pixel_8u pixel,
				const t_coord rack_size);
void			draw_circle(
				t_mlx_image_8u *dst,
				const t_coord center,
				const int radius,
				const t_pixel_8u pixel);
void			draw_circle_in_roi(
				t_mlx_image_8u *dst,
				const t_roi roi,
				const t_pixel_8u pixel);
void			draw_disk(
				t_mlx_image_8u *dst,
				const t_coord center,
				const int radius,
				const t_pixel_8u pixel);
void			draw_disk_in_roi(
				t_mlx_image_8u *dst,
				const t_roi roi,
				const t_pixel_8u pixel);
t_color_8u		pixel_to_color_8u(const t_pixel_8u pixel);
t_pixel_8u		color_to_pixel_8u(const t_color_8u color);

#endif
