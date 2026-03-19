/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 13:53:58 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (ray->map_x < 0 || ray->map_x >= game->map_width
			|| ray->map_y < 0 || ray->map_y >= game->map_height)
			ray->hit = 1;
		else if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

// RENDER ONE FULL 3D FRAME
void	ft_raycast_frame(t_game *game)
{
	t_ray	ray;
	int		x;

	ft_draw_floor_ceiling_textured(game);
	x = 0;
	while (x < game->win_width)
	{
		ft_init_ray(&ray, game, x);
		ft_perform_dda(&ray, game);
		ft_calculate_wall_height(&ray, game);
		game->z_buffer[x] = ray.perp_wall_dist;
		ft_draw_wall_column(game, &ray, x);
		x += RAYCAST_COLUMN_STEP;
	}
	ft_draw_weapon_hud(game);
	ft_draw_crosshair(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}
