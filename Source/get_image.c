// Created by Onur Dursun on 10/24/22.

#include "cub3d.h"

void	get_image(t_main *main)
{
	int x;
	int y;

	x = 0;
	y = 0;
	main->block = mlx_xpm_file_to_image(main->mlx, main->dir[0], &x, &y);
	main->floor = mlx_xpm_file_to_image(main->mlx, main->dir[1], &x, &y);

}
