#include "../../../includes/bonus/cub3d_bonus.h"

int	ft_close_game(t_game *game)
{
	ft_free_game(game);
	_exit(0);
}

int	ft_mouse_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		ft_shoot(game);
	return (0);
}
