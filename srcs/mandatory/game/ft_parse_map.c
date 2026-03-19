/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 15:17:01 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

int	ft_parse_config_line(t_game *game, char *line);
int	ft_read_cub_lines(t_game *game, char *filename);
int	ft_finalize_map_shape(t_game *game);
int	ft_validate_chars_and_spawn(t_game *game);
int	ft_validate_map(t_game *game);

static int	ft_has_required_config(t_game *game)
{
	if (!game->tex_no_path || !game->tex_so_path)
		return (0);
	if (!game->tex_we_path || !game->tex_ea_path)
		return (0);
	if (!game->has_floor_color || !game->has_ceiling_color)
		return (0);
	return (1);
}

int	ft_parse_map(t_game *game, char *filename)
{
	if (!ft_read_cub_lines(game, filename))
		return (ft_putstr_fd("Error\nInvalid .cub file\n", 2), 0);
	if (!ft_has_required_config(game))
		return (ft_putstr_fd("Error\nMissing config values\n", 2), 0);
	if (!ft_finalize_map_shape(game))
		return (ft_putstr_fd("Error\nInvalid map data\n", 2), 0);
	if (!ft_validate_chars_and_spawn(game))
		return (ft_putstr_fd("Error\nInvalid map characters/spawn\n", 2), 0);
	if (!ft_validate_map(game))
		return (ft_putstr_fd("Error\nMap is not closed\n", 2), 0);
	ft_find_player_spawn(game);
	game->original_map = ft_mapdup(game->map);
	if (!game->original_map)
		return (0);
	return (1);
}
