#include "../../../includes/mandatory/cub3d.h"

static void	ft_move_by_direction(t_game *g, double dx, double dy)
{
	double	step;

	step = MOVE_SPEED * g->timing.delta_time;
	if (!ft_check_wall(g, g->player.pos_x + dx * step, g->player.pos_y))
		g->player.pos_x += dx * step;
	if (!ft_check_wall(g, g->player.pos_x, g->player.pos_y + dy * step))
		g->player.pos_y += dy * step;
}

void	ft_move_forward(t_game *game)
{
	ft_move_by_direction(game, game->player.dir_x, game->player.dir_y);
}

void	ft_move_backward(t_game *game)
{
	ft_move_by_direction(game, -game->player.dir_x, -game->player.dir_y);
}

void	ft_move_left(t_game *game)
{
	ft_move_by_direction(game, -game->player.plane_x, -game->player.plane_y);
}

void	ft_move_right(t_game *game)
{
	ft_move_by_direction(game, game->player.plane_x, game->player.plane_y);
}
