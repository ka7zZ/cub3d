/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 13:52:40 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

// GAME INIT STAGE UTILS

// INIT MAP PARSING AND WINDOW CONTEXT
int	ft_init_stage_map_window(t_game *game, char *map_file)
{
	if (!ft_parse_map(game, map_file))
		return (0);
	ft_init_mlx(game);
	return (1);
}

int	ft_init_stage_assets_world(t_game *game)
{
	if (!ft_load_textures(game))
		return (0);
	return (1);
}

// INIT RUNTIME FLAGS
void	ft_init_stage_runtime(t_game *game)
{
	game->frame_count = 0;
	game->delta_time = 0.016;
	game->last_frame_us = 0;
}
