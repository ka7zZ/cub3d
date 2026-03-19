#include "../../../includes/mandatory/cub3d.h"

static t_texture	*ft_select_oriented_wall(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (&game->tex_wall[2]);
		return (&game->tex_wall[3]);
	}
	if (ray->dir_y > 0)
		return (&game->tex_wall[0]);
	return (&game->tex_wall[1]);
}

t_texture	*ft_select_texture(t_game *game, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_y >= game->map_height)
		return (&game->tex_wall[0]);
	if (ray->map_x < 0 || ray->map_x >= game->map_width)
		return (&game->tex_wall[0]);
	if (game->map[ray->map_y][ray->map_x] != '1')
		return (&game->tex_wall[0]);
	return (ft_select_oriented_wall(game, ray));
}
