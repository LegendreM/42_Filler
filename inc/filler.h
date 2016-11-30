#ifndef FILLER_H
# define FILLER_H

# include <mlx.h>
# include <stdlib.h>

# include "./libft.h"
# include "./mlxlibft.h"
# include "./get_next_line.h"
/*
@name: t_params
@brief: struct returned by parser and passed as parameter to AI
@attr:
	@name: game_board
	@type: char**
	@brief: map of the game,
	each line finish by '\0'
	the last line is a null pointer
@attr:
	@name: game_piece
	@type: char**
	@brief: piece to place on the game_board,
	each line finish by '\0'
	the last line is a null pointer
@attr:
	@name: coord
	@brief: struct wich contain coord of game_piece
*/

typedef struct	s_params
{
	char		player;
	int			count_line;
	char		**game_board;
	char		**game_piece;
	t_coord		board_size;
	t_coord		piece_size;
	t_coord		coord;
}				t_params;

typedef struct	s_env
{
	t_mlx_env		*mlx;
	t_mlx_image_8u	*win_img;
}				t_env;

int		start_gui(void);
int		loop_hook(t_env *env);
int		expose(t_env *env);
t_roi	*draw_game_rack(
			t_mlx_image_8u *dst,
			const t_pixel_8u pixel,
			const int rack_width,
			const int rack_height
		);

char	**ft_matrixnew(const size_t y, const size_t x);
t_params	*parser(void);
int			ai_dv(t_params *params, int to_play[]);
void		play(int x, int y); //where do u want play the next piece
#endif
