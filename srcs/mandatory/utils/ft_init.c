#include "../../../includes/mandatory/cub3d.h"

void	ft_init_mlx(t_game *game)
{
	int	screen_width;
	int	screen_height;

	game->graphics.mlx = mlx_init();
	if (!game->graphics.mlx)
		ft_exit_error(game, "MLX initialization failed");
	mlx_get_screen_size(game->graphics.mlx, &screen_width, &screen_height);
	game->graphics.win_width = screen_width;
	game->graphics.win_height = screen_height;
	game->graphics.win = mlx_new_window(game->graphics.mlx, game->graphics.win_width,
			game->graphics.win_height, "so_long 3D");
	if (!game->graphics.win)
		ft_exit_error(game, "Window creation failed");
	game->graphics.frame.img = mlx_new_image(game->graphics.mlx,
			game->graphics.win_width, game->graphics.win_height);
	if (!game->graphics.frame.img)
		ft_exit_error(game, "Image creation failed");
	game->graphics.frame.addr = mlx_get_data_addr(game->graphics.frame.img,
			&game->graphics.frame.bpp, &game->graphics.frame.line_len, &game->graphics.frame.endian);
}

int	ft_init_game(t_game *game, char *map_file)
{
	ft_memset(game, 0, sizeof(t_game));
	if (!ft_init_stage_map_window(game, map_file))
	{
		ft_free_game(game);
		return (0);
	}
	if (!ft_init_stage_assets_world(game))
	{
		ft_free_game(game);
		return (0);
	}
	ft_init_stage_runtime(game);
	ft_print_controls();
	return (1);
}
