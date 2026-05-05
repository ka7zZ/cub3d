#include "../../../includes/mandatory/cub3d.h"

void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->graphics.frame.img && game->graphics.mlx)
		mlx_destroy_image(game->graphics.mlx, game->graphics.frame.img);
	if (game->graphics.mlx)
		ft_free_textures(game);
	if (game->graphics.win && game->graphics.mlx)
		mlx_destroy_window(game->graphics.mlx, game->graphics.win);
	if (game->graphics.mlx)
	{
		mlx_destroy_display(game->graphics.mlx);
		free(game->graphics.mlx);
		game->graphics.mlx = NULL;
	}
	ft_mapfree(&game->map.map);
	free(game->assets.tex_no_path);
	free(game->assets.tex_so_path);
	free(game->assets.tex_we_path);
	free(game->assets.tex_ea_path);
}

void	ft_exit_error(t_game *game, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (game)
		ft_free_game(game);
	exit(1);
}
