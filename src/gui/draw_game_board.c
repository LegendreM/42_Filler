#include "filler.h"

void	draw_game_board(t_mlx_image_8u *dst,
						const t_params *params)
{
	t_roi		*rack;
	t_pixel_8u	pix;
	int			i;

	clear_image_8u(dst, create_pixel_8u(0x2f, 0x2f, 0x2f, 0x00));
	rack = draw_game_rack(dst, create_pixel_8u(0x9f, 0x9f, 0x9f, 0x00),
					 params->board_size.x, params->board_size.y);
	i = 0;
	while (i < params->board_size.x * params->board_size.y)
	{
		if (params->game_board[0][i] != '.')
		{
			if (params->game_board[0][i] == 'O')
				pix = RED_PX;
			else
				pix = BLUE_PX;
			draw_disk_in_roi(dst, rack[i], pix);
		}
		++i;
	}
}
