#include "filler.h"

void	draw_game_rack(t_mlx_image_8u *dst,
						const t_pixel_8u pixel,
						const int rack_width,
						const int rack_height)
{
	const int		ww = dst->width;
	const int		wh = dst->height;
	const t_coord	rack_size = {.x = rack_width, .y = rack_height};
	const t_roi		roi = create_roi(ww / 10, wh / 10,

	ww * 8 / 10, wh * 8 / 10);
	draw_rack(dst, roi, pixel, rack_size);
}