#include "../../../includes/mandatory/cub3d.h"

static void	ft_draw_pixels(t_game *g, t_ray *r, t_texture *tx, int x, int darken)
{
	double	step;
	double	pos;
	char	*addr;
	int		stride;
	int		y;
	int		off;
	int		color;

	step = 1.0 * tx->height / r->line_height;
	pos = (r->draw_start - G_HEIGHT(g) / 2 + r->line_height / 2) * step;
	addr = G_FRAME(g)->addr;
	stride = G_FRAME(g)->line_len;
	off = x * (G_FRAME(g)->bpp / 8);
	y = r->draw_start;
	while (y < r->draw_end - 1)
	{
		color = ft_get_texture_color(tx, r->tex_x, ((int)pos) & (tx->height - 1));
		*(unsigned int *)(addr + y * stride + off) = darken ? \
			((color >> 1) & 8355711) : color;
		pos += step;
		y++;
		color = ft_get_texture_color(tx, r->tex_x, ((int)pos) & (tx->height - 1));
		*(unsigned int *)(addr + y * stride + off) = darken ? \
			((color >> 1) & 8355711) : color;
		pos += step;
		y++;
	}
	while (y < r->draw_end)
	{
		color = ft_get_texture_color(tx, r->tex_x, ((int)pos) & (tx->height - 1));
		*(unsigned int *)(addr + y * stride + off) = darken ? \
			((color >> 1) & 8355711) : color;
		pos += step;
		y++;
	}
}

void	ft_draw_wall_column(t_game *game, t_ray *ray, int x)
{
	t_texture	*tex;

	tex = ft_select_texture(game, ray);
	if (!tex)
		return ;
	ray->tex_x = (int)(ray->wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		ray->tex_x = tex->width - ray->tex_x - 1;
	ft_draw_pixels(game, ray, tex, x, ray->side);
}
