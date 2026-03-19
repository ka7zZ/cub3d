#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_set_move_key(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W)
		game->key_w = 1;
	if (keycode == XK_s || keycode == XK_S)
		game->key_s = 1;
	if (keycode == XK_a || keycode == XK_A)
		game->key_a = 1;
	if (keycode == XK_d || keycode == XK_D)
		game->key_d = 1;
	if (keycode == XK_Left)
		game->key_left = 1;
	if (keycode == XK_Right)
		game->key_right = 1;
}

static void	ft_clear_move_key(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W)
		game->key_w = 0;
	if (keycode == XK_s || keycode == XK_S)
		game->key_s = 0;
	if (keycode == XK_a || keycode == XK_A)
		game->key_a = 0;
	if (keycode == XK_d || keycode == XK_D)
		game->key_d = 0;
	if (keycode == XK_Left)
		game->key_left = 0;
	if (keycode == XK_Right)
		game->key_right = 0;
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		ft_close_game(game);
	ft_set_move_key(keycode, game);
	if (keycode == XK_e || keycode == XK_E)
		ft_handle_interaction(game);
	if (keycode == XK_r || keycode == XK_R)
		ft_reload_shotgun(game);
	return (0);
}

int	ft_key_release(int keycode, t_game *game)
{
	ft_clear_move_key(keycode, game);
	return (0);
}
