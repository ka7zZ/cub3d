#include "../../../includes/mandatory/cub3d.h"

static void	ft_draw_line(t_game *g, int x, int y, int dx, int c1, int c2)
{
	int	i;

	i = 4;
	while (i <= 14)
	{
		ft_put_pixel(G_FRAME(g), x + dx * i, y - 1, c1);
		ft_put_pixel(G_FRAME(g), x + dx * i, y + 1, c1);
		ft_put_pixel(G_FRAME(g), x - dx * i, y - 1, c1);
		ft_put_pixel(G_FRAME(g), x - dx * i, y + 1, c1);
		ft_put_pixel(G_FRAME(g), x + dx * i, y, c2);
		ft_put_pixel(G_FRAME(g), x - dx * i, y, c2);
		i++;
	}
}

void	ft_draw_crosshair(t_game *game)
{
	int	cx;
	int	cy;

	cx = G_WIDTH(game) / 2;
	cy = G_HEIGHT(game) / 2;
	ft_draw_line(game, cx, cy, 1, 0x000000, 0xFFFFFF);
	ft_draw_line(game, cx, cy, 0, 0x000000, 0xFFFFFF);
	ft_put_pixel(G_FRAME(game), cx, cy, 0xFFFFFF);
}

static void	ft_draw_weapon_pixel(t_game *g, t_texture *t, int x, int y)
{
	int	color;

	color = ft_get_texture_color(t, (x * t->width) / 400, (y * t->height) / 300);
	if ((color & 0xFF000000) != 0xFF000000)
		ft_put_pixel(G_FRAME(g), G_WIDTH(g) / 2 - 200 + x + 80,
			G_HEIGHT(g) - 300 + y, color);
}

void	ft_draw_weapon_hud(t_game *game)
{
	t_texture	*tex;
	int			x;
	int			y;

	tex = &game->assets.tex_weapon;
	if (!tex->img)
		return ;
	y = 0;
	while (y < 300)
	{
		x = 0;
		while (x < 400)
		{
			ft_draw_weapon_pixel(game, tex, x, y);
			x++;
		}
		y++;
	}
}
