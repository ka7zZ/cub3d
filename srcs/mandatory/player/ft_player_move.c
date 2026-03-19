/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:17:09 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 12:22:41 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

void	ft_move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->player.pos_x + game->player.dir_x * step;
	new_y = game->player.pos_y + game->player.dir_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		game->player.moves++;
	}
	if (!ft_check_wall(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		game->player.moves++;
	}
}

void	ft_move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->player.pos_x - game->player.dir_x * step;
	new_y = game->player.pos_y - game->player.dir_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		game->player.moves++;
	}
	if (!ft_check_wall(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		game->player.moves++;
	}
}

void	ft_move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->player.pos_x - game->player.plane_x * step;
	new_y = game->player.pos_y - game->player.plane_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		game->player.moves++;
	}
	if (!ft_check_wall(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		game->player.moves++;
	}
}

void	ft_move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->player.pos_x + game->player.plane_x * step;
	new_y = game->player.pos_y + game->player.plane_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		game->player.moves++;
	}
	if (!ft_check_wall(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		game->player.moves++;
	}
}
