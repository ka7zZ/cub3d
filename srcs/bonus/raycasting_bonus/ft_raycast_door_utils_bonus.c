/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_door_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 12:06:22 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

// RAYCAST DOOR UTILS

// CHECK IF CURRENT RAY CELL IS A DOOR
int	ft_is_door_cell(t_game *game, t_ray *ray)
{
	if (ray->map_x < 0 || ray->map_x >= game->map_width
		|| ray->map_y < 0 || ray->map_y >= game->map_height)
		return (0);
	return (game->map[ray->map_y][ray->map_x] == 'D');
}

// CONTINUE DDA UNTIL A SOLID WALL AFTER THE DOOR
void	ft_continue_dda_after_door(t_ray *ray, t_game *game)
{
	ray->hit = 0;
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
		{
			ray->hit = 1;
			break ;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}
