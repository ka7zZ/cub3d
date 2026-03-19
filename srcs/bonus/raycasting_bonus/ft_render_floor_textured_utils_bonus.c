/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_floor_textured_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 12:40:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_draw_floor_ceiling_textured(t_game *game)
{
	int	x;
	int	y;
	int	horizon;

	horizon = game->win_height / 2 + game->player.pitch;
	if (horizon < 0)
		horizon = 0;
	if (horizon > game->win_height)
		horizon = game->win_height;
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			if (y < horizon)
				ft_put_pixel(&game->frame, x, y, game->ceiling_color);
			else
				ft_put_pixel(&game->frame, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}
