#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_draw_floor_ceiling_textured(t_game *game)
{
	int	x;
	int	y;
	int	horizon;

	horizon = game->win_height / 2 + game->player.pitch;
	if (horizon < 0)
		horizon = 0;
	if (horizon > game->win_height)
		horizon = game->win_height;
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			if (y < horizon)
				ft_put_pixel(&game->frame, x, y, game->ceiling_color);
			else
				ft_put_pixel(&game->frame, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}
