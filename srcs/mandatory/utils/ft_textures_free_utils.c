#include "../../../includes/mandatory/cub3d.h"

void	ft_free_dual_wall_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g->tex_wall[i].img)
			mlx_destroy_image(g->mlx, g->tex_wall[i].img);
		i++;
	}
}
