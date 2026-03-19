/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 13:52:40 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

int	ft_close_game(t_game *game)
{
	ft_free_game(game);
	_exit(0);
}
