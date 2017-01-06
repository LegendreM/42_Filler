/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 09:14:11 by jle-mene          #+#    #+#             */
/*   Updated: 2017/01/06 11:34:25 by jle-mene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# define GUI 0
# define BUFFSIZE 8
# define FD 0
# define SPEED 5000

# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "mlxlibft.h"
# include "get_next_line.h"

/*
**	STRUCTURES
*/

typedef struct	s_params
{
	char		player[3];
	int			count_line;
	char		**game_board;
	char		**game_piece;
	char		**game_piece_min;
	t_coord		board_size;
	t_coord		piece_size;
	t_coord		piece_size_min;
	t_coord		piece_orig;
}				t_params;

typedef struct	s_env
{
	t_mlx_env		*mlx;
	t_mlx_image_8u	*win_img;
	t_params		*params;
}				t_env;

/*
**	GUI
*/

int				start_gui(void);
int				loop_hook(t_env *env);
int				expose(t_env *env);
t_roi			*draw_game_rack(
					t_mlx_image_8u *dst,
					const t_pixel_8u pixel,
					const int rack_width,
					const int rack_height);
void			draw_game_board(t_mlx_image_8u *dst,
					const t_params *params);

/*
**	PARSER
*/

int				start_filler(void);
t_params		*parser(t_params *params);
void			set_piece(char *line, t_params *params);
void			play(t_coord params, int x, int y);
char			**ft_matrixnew(const size_t y, const size_t x);
void			ft_matrixdel(char **map);

/*
**	AI
*/

int				ai_launch(t_params *params, t_coord *to_play);
int				get_possible_positions(t_params *params, t_coord *pos);
t_coord			mid_points(t_params *params);
int				place_piece(t_params *params, t_coord coord);
int				reset_piece(t_params *params, t_coord coord);
int				get_dist(t_coord start_point, t_coord end_point);

#endif
