#include "../../../includes/mandatory/cub3d.h"

int	ft_close_game(t_game *game)
{
	ft_free_game(game);
	_exit(0);
}
