// Created by Onur Dursun on 10/24/22.

#include "cub3d.h"

int	walk(int keycode, t_main *main)
{
	if (keycode == 53)
		close_frame(main);
	if (keycode == key_a)
		main->mx -= 5;
	if (keycode == key_d)
		main->mx += 5;
	if (keycode == key_w)
		main->my -= 5;
	if (keycode == key_s)
		main->my += 5;
	mlx_clear_window(main->mlx, main->win);
	ft_draw(main);
	return (keycode);
}
