#ifndef FILLER_H
# define FILLER_H
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
*/
typedef struct	s_params
{
	char		**game_board;
	char		**game_piece;	
}				t_params;

#endif