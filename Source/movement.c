// Created by Onur Dursun on 10/24/22.

#include "cub3d.h"

int	walk(int keycode, t_main *main)
{
	if (keycode == 53)
		close_frame(main);
	if (keycode == KEY_A)
		main->mx -= 10;
	if (keycode == KEY_D)
		main->mx += 10;
	if (keycode == KEY_W)
		main->my -= 10;
	if (keycode == KEY_S)
		main->my += 10;
	mlx_clear_window(main->mlx, main->win);
	ft_draw(main);
	return (keycode);
}
