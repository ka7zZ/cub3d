/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_validate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 15:17:01 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

int	ft_validate_chars_and_spawn(t_game *game)
{
	int	y;
	int	x;
	int	spawn_count;

	spawn_count = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (!ft_strchr(" 01NSEW", game->map[y][x]))
				return (0);
			if (ft_strchr("NSEW", game->map[y][x]))
				spawn_count++;
			x++;
		}
		y++;
	}
	return (spawn_count == 1);
}

static int	ft_cell_touches_void(t_game *game, int y, int x)
{
	if (y == 0 || x == 0)
		return (1);
	if (y == game->map_height - 1 || x == game->map_width - 1)
		return (1);
	if (game->map[y - 1][x] == ' ' || game->map[y + 1][x] == ' ')
		return (1);
	if (game->map[y][x - 1] == ' ' || game->map[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	ft_validate_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (ft_strchr("0NSEW", game->map[y][x])
				&& ft_cell_touches_void(game, y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
