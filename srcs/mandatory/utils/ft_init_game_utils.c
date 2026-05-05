#include "../../../includes/mandatory/cub3d.h"

// GAME INIT STAGE UTILS

// INIT MAP PARSING AND WINDOW CONTEXT
int	ft_init_stage_map_window(t_game *game, char *map_file)
{
	if (!ft_parse_map(game, map_file))
		return (0);
	ft_init_mlx(game);
	return (1);
}

int	ft_init_stage_assets_world(t_game *game)
{
	if (!ft_load_textures(game))
		return (0);
	return (1);
}

// INIT RUNTIME FLAGS
void	ft_init_stage_runtime(t_game *game)
{
	game->timing.frame_count = 0;
	game->timing.delta_time = 0.016;
	game->timing.last_frame_us = 0;
}
