#include "mlxlibft.h"
#include "filler.h"

void	draw_rack_in_image(
		t_mlx_image_8u *dst,
		const t_roi roi,
		const t_pixel_8u pixel,
		const t_coord rack_size
		)
{
	const t_coord	case_size = {.x = roi.width / rack_size.x,
								.y = roi.height / rack_size.y};
	t_coord			img_coord;
	t_coord			rack_coord;

	img_coord.x = t_roi.x;
	img_coord.y = t_roi.y;
	rack_coord.y = 0;
	while (rack_coord.y < rack_size.y)
	{
		draw_square(dst, build_roi(img_coord.x, img_coord.y,
					case_size.x * rack_size.x, 1), pixel)
		img_coord.y += case_size.y;
		++rack_coord.y;
	}
	img_coord.y = t_roi.y;
	rack_coord.x = 0;
	while (rack_coord.x < rack_size.x)
	{
		draw_square(dst, build_roi(img_coord.x, img_coord.y, 1,
					case_size.y * rack_size.y), pixel)
		img_coord.x += case_size.x;
		++rack_coord.x;
	}
}