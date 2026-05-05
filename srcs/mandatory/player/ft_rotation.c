#include "../../../includes/mandatory/cub3d.h"

static void	ft_rotate_by_angle(t_game *g, double angle)
{
	double	c;
	double	s;
	double	old_dx;
	double	old_px;

	c = cos(angle);
	s = sin(angle);
	old_dx = g->player.dir_x;
	old_px = g->player.plane_x;
	g->player.dir_x = old_dx * c - g->player.dir_y * s;
	g->player.dir_y = old_dx * s + g->player.dir_y * c;
	g->player.plane_x = old_px * c - g->player.plane_y * s;
	g->player.plane_y = old_px * s + g->player.plane_y * c;
}

void	ft_update_player(t_game *game)
{
	double	rot_step;

	if (game->input.key_w)
		ft_move_forward(game);
	if (game->input.key_s)
		ft_move_backward(game);
	if (game->input.key_a)
		ft_move_left(game);
	if (game->input.key_d)
		ft_move_right(game);
	rot_step = ROT_SPEED * game->timing.delta_time;
	if (game->input.key_left)
		ft_rotate_by_angle(game, rot_step);
	if (game->input.key_right)
		ft_rotate_by_angle(game, -rot_step);
}
