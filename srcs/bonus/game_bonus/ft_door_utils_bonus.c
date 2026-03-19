/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 11:34:58 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_init_doors(t_game *game)
{
	int	y;
	int	x;

	game->door_count = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'D' && game->door_count < MAX_DOORS)
			{
				game->doors[game->door_count].map_x = x;
				game->doors[game->door_count].map_y = y;
				game->doors[game->door_count].is_open = 0;
				game->doors[game->door_count].animation_progress = 0.0;
				game->doors[game->door_count].opened_at_frame = 0;
				game->door_count++;
			}
			x++;
		}
		y++;
	}
}
