/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/17 13:52:40 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

int	ft_load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		if (path)
			ft_putstr_fd(path, 2);
		else
			ft_putstr_fd("(null)", 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
	{
		mlx_destroy_image(game->mlx, tex->img);
		return (0);
	}
	return (1);
}

int	ft_load_textures(t_game *game)
{
	if (!ft_load_wall_textures(game))
		return (0);
	if (!ft_load_floor_textures(game))
		return (0);
	if (!ft_load_texture(game, &game->tex_weapon,
			"assets/ingame/gun/(1)sgun_normal.xpm"))
		return (0);
	return (1);
}

void	ft_free_textures(t_game *game)
{
	ft_free_dual_wall_textures(game);
	if (game->tex_weapon.img)
		mlx_destroy_image(game->mlx, game->tex_weapon.img);
}
