#include "filler.h"

void	draw_game_board(t_mlx_image_8u *dst,
						const t_params *params)
{
	t_roi		*rack;
	t_pixel_8u	pix;
	int 		i;


	// ft_putendl_fd("salut2", 2);
	clear_image_8u(dst, create_pixel_8u(0x2f, 0x2f, 0x2f, 0x00));
	rack = draw_game_rack(dst, create_pixel_8u(0x9f, 0x9f, 0x9f, 0x00),
					 params->board_size.x, params->board_size.y);
	i = 0;
	// ft_putendl_fd("salut", 2);
	while (i < params->board_size.x * params->board_size.y)
	{
		if (params->game_board[0][i] != '.')
		{
			if (params->game_board[0][i] == 'o')
				pix = RED_PX;
			else if (params->game_board[0][i] == 'O')
				pix = LIGHT_RED_PX;
			else if (params->game_board[0][i] == 'x')
				pix = BLUE_PX;
			else
				pix = LIGHT_BLUE_PX;
			draw_disk_in_roi(dst, rack[i], pix);
			// ft_putnbr(i);
			// ft_putstr(" - ");
			// ft_putnbr(params->board_size.x * params->board_size.y);
			// ft_putstr("\n");
		}
		++i;
	}
}