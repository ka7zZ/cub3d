#include "../../../includes/mandatory/cub3d.h"

// RUN DDA UNTIL WALL HIT
void	ft_perform_dda(t_ray *ray, t_game *game)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= game->map.map_width
			|| ray->map_y < 0 || ray->map_y >= game->map.map_height)
			ray->hit = 1;
		else if (game->map.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

// COPY COLUMN TO ADJACENT COLUMN FOR PERFORMANCE MODE - UNROLLED
static void	ft_copy_column(t_game *game, int from_x, int to_x)
{
	char	*base;
	int		off_from;
	int		off_to;
	int		stride;
	int		y;

	base = G_FRAME(game)->addr;
	stride = G_FRAME(game)->line_len;
	off_from = from_x * (G_FRAME(game)->bpp / 8);
	off_to = to_x * (G_FRAME(game)->bpp / 8);
	y = 0;
	while (y < G_HEIGHT(game) - 3)
	{
		*(unsigned int *)(base + y * stride + off_to) = \
			*(unsigned int *)(base + y * stride + off_from);
		*(unsigned int *)(base + (y + 1) * stride + off_to) = \
			*(unsigned int *)(base + (y + 1) * stride + off_from);
		*(unsigned int *)(base + (y + 2) * stride + off_to) = \
			*(unsigned int *)(base + (y + 2) * stride + off_from);
		*(unsigned int *)(base + (y + 3) * stride + off_to) = \
			*(unsigned int *)(base + (y + 3) * stride + off_from);
		y += 4;
	}
	while (y < G_HEIGHT(game))
	{
		*(unsigned int *)(base + y * stride + off_to) = \
			*(unsigned int *)(base + y * stride + off_from);
		y++;
	}
}

// RENDER ONE FULL 3D FRAME - PHASE 4: 2x loop unrolling for RAYCAST_COLUMN_STEP=2
void	ft_raycast_frame(t_game *game)
{
	t_ray	ray;
	int		x;

	ft_draw_floor_ceiling_textured(game);
	x = 0;
	while (x < G_WIDTH(game) - 2)
	{
		ft_init_ray(&ray, game, x);
		ft_perform_dda(&ray, game);
		ft_calculate_wall_height(&ray, game);
		ft_draw_wall_column(game, &ray, x);
		if (RAYCAST_COLUMN_STEP == 2 && x + 1 < G_WIDTH(game))
			ft_copy_column(game, x, x + 1);
		x += RAYCAST_COLUMN_STEP;
		if (x < G_WIDTH(game))
		{
			ft_init_ray(&ray, game, x);
			ft_perform_dda(&ray, game);
			ft_calculate_wall_height(&ray, game);
			ft_draw_wall_column(game, &ray, x);
			if (RAYCAST_COLUMN_STEP == 2 && x + 1 < G_WIDTH(game))
				ft_copy_column(game, x, x + 1);
			x += RAYCAST_COLUMN_STEP;
		}
	}
	while (x < G_WIDTH(game))
	{
		ft_init_ray(&ray, game, x);
		ft_perform_dda(&ray, game);
		ft_calculate_wall_height(&ray, game);
		ft_draw_wall_column(game, &ray, x);
		if (RAYCAST_COLUMN_STEP == 2 && x + 1 < G_WIDTH(game))
			ft_copy_column(game, x, x + 1);
		x += RAYCAST_COLUMN_STEP;
	}
	ft_draw_weapon_hud(game);
	ft_draw_crosshair(game);
	mlx_put_image_to_window(game->graphics.mlx, game->graphics.win, game->graphics.frame.img, 0, 0);
}
