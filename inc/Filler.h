#ifndef FILLER_H
# define FILLER_H
/*
@name: t_coord
@brief: struct wich contain coord
@attr:
	@name: x
	@type: int
	@brief: x coord
@attr:
	@name: y
	@type: int
	@brief: y coord
*/
typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

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
	char		**game_board;
	char		**game_piece;
	t_coord		coord;
}				t_params;

void	draw_rack_in_image(
		t_mlx_image_8u *dst,
		const t_roi roi,
		const t_pixel_8u color,
		const t_coord rack_size
		);

#endif