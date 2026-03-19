/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_floor_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:00:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/03/13 15:57:56 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

void	ft_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_get_texture_color(t_texture *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}
