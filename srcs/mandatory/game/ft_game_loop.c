/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 15:17:01 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"
#include <sys/time.h>

static long long	ft_now_us(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec);
}

static void	ft_update_delta_time(t_game *game)
{
	long long	now;

	now = ft_now_us();
	if (game->last_frame_us == 0)
		game->delta_time = 0.016;
	else
		game->delta_time = (double)(now - game->last_frame_us) / 1000000.0;
	if (game->delta_time < MIN_DELTA_TIME)
		game->delta_time = MIN_DELTA_TIME;
	if (game->delta_time > MAX_DELTA_TIME)
		game->delta_time = MAX_DELTA_TIME;
	game->last_frame_us = now;
}

static int	ft_cell_blocks_player(t_game *game, int map_x, int map_y)
{
	if (map_x < 0 || map_x >= game->map_width
		|| map_y < 0 || map_y >= game->map_height)
		return (1);
	if (game->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	ft_check_wall(t_game *game, double x, double y)
{
	int	ix;
	int	iy;
	int	m[2];

	iy = -1;
	while (iy <= 1)
	{
		ix = -1;
		while (ix <= 1)
		{
			m[0] = (int)(x + ix * PLAYER_RADIUS);
			m[1] = (int)(y + iy * PLAYER_RADIUS);
			if (ft_cell_blocks_player(game, m[0], m[1]))
				return (1);
			ix++;
		}
		iy++;
	}
	return (0);
}

int	ft_game_loop(t_game *game)
{
	ft_update_delta_time(game);
	game->frame_count++;
	ft_update_player(game);
	ft_raycast_frame(game);
	return (0);
}
