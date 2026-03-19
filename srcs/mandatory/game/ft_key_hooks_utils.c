#include "../../../includes/mandatory/cub3d.h"

// KEYBOARD INPUT UTILS

// SET MOVEMENT FLAGS ON KEY PRESS
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

// CLEAR MOVEMENT FLAGS ON KEY RELEASE
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

// HANDLE KEY PRESS ACTIONS
int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		ft_close_game(game);
	ft_set_move_key(keycode, game);
	return (0);
}

// HANDLE KEY RELEASE ACTIONS
int	ft_key_release(int keycode, t_game *game)
{
	ft_clear_move_key(keycode, game);
	return (0);
}
