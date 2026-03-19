/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_3d_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 13:52:41 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

int	ft_close_game(t_game *game)
{
	ft_free_game(game);
	_exit(0);
}

int	ft_mouse_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		ft_shoot(game);
	return (0);
}
