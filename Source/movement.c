// Created by Onur Dursun on 10/24/22.

#include "cub3d.h"

int	walk(int keycode, t_main *main)
{
	printf("keycode ==== {%d}\n", keycode);
	if (keycode == KEY_W)
	{
		main->my -= 10.0 * sin((-main->angle) * (PI / 180));
		main->mx += 10.0 * cos((main->angle) * (PI / 180));
	}
	if (keycode == KEY_S)
	{
		main->my += 10.0 * sin((-main->angle) * (PI / 180));
		main->mx -= 10.0 * cos((main->angle) * (PI / 180));
	}
	if (keycode == 53)
		close_frame(main);
	if (keycode == KEY_A)
	{
		main->my -= 10.0 * cos((main->angle) * (PI / 180));
		main->mx += 10.0 * sin((main->angle) * (PI / 180));
	}
	if (keycode == KEY_D)
	{
		main->my += 10.0 * cos((main->angle) * (PI / 180));
		main->mx -= 10.0 * sin((main->angle) * (PI / 180));
	}
	if (keycode == 124)
		main->angle += 5;
	if (keycode == 123)
		main->angle -= 5;
	mlx_clear_window(main->mlx, main->win);
	ft_draw(main);
	return (keycode);
}
