/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_load_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:10:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 13:52:40 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static int	ft_load_dark_walls(t_game *g)
{
	if (!ft_load_texture(g, &g->tex_wall[0], g->tex_no_path))
		return (0);
	if (!ft_load_texture(g, &g->tex_wall[1], g->tex_so_path))
		return (0);
	if (!ft_load_texture(g, &g->tex_wall[2], g->tex_we_path))
		return (0);
	if (!ft_load_texture(g, &g->tex_wall[3], g->tex_ea_path))
		return (0);
	return (1);
}

int	ft_load_wall_textures(t_game *g)
{
	return (ft_load_dark_walls(g));
}

int	ft_load_floor_textures(t_game *g)
{
	(void)g;
	return (1);
}
