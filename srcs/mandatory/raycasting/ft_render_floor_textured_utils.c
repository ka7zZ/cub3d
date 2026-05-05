#include "../../../includes/mandatory/cub3d.h"

void	ft_draw_floor_ceiling_textured(t_game *g)
{
	char	*addr;
	int		stride;
	int		ps;
	int		y;
	int		x;
	int		w;
	int		mid;
	int		c;

	addr = G_FRAME(g)->addr;
	stride = G_FRAME(g)->line_len;
	ps = G_FRAME(g)->bpp / 8;
	w = G_WIDTH(g);
	mid = G_HEIGHT(g) / 2;
	y = 0;
	while (y < G_HEIGHT(g))
	{
		c = (y < mid) ? G_CEIL_C(g) : G_FLOOR_C(g);
		x = 0;
		while (x < w - 3)
		{
			*(unsigned int *)(addr + y * stride + x * ps) = c;
			*(unsigned int *)(addr + y * stride + (x + 1) * ps) = c;
			*(unsigned int *)(addr + y * stride + (x + 2) * ps) = c;
			*(unsigned int *)(addr + y * stride + (x + 3) * ps) = c;
			x += 4;
		}
		while (x < w)
			*(unsigned int *)(addr + y * stride + x++ * ps) = c;
		y++;
	}
}
