/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 12:40:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_rotate_player(t_game *game, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos(rot) - game->player.dir_y * sin(rot);
	game->player.dir_y = old_dir_x * sin(rot) + game->player.dir_y * cos(rot);
	game->player.plane_x = old_plane_x * cos(rot)
		- game->player.plane_y * sin(rot);
	game->player.plane_y = old_plane_x * sin(rot)
		+ game->player.plane_y * cos(rot);
}

void	ft_update_player(t_game *game)
{
	double	rot_step;

	if (game->key_w)
		ft_move_forward(game);
	if (game->key_s)
		ft_move_backward(game);
	if (game->key_a)
		ft_move_left(game);
	if (game->key_d)
		ft_move_right(game);
	rot_step = ROT_SPEED * game->delta_time;
	if (game->key_left)
		ft_rotate_player(game, rot_step);
	if (game->key_right)
		ft_rotate_player(game, -rot_step);
}
