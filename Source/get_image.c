// Created by Onur Dursun on 10/24/22.

#include "cub3d.h"

void	get_image(t_main *main)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	//if (open(main->dir[0], O_RDONLY) == -1)
	//	ft_putendl_fd("1Error\nNO texture not found\n", 2);
	main->block = mlx_xpm_file_to_image(main->mlx, main->dir[0], &x, &y);
	//if (open(main->dir[1], O_RDONLY) == -1)
	//	ft_putendl_fd("2Error\nNO texture not found\n", 2);
	main->floor = mlx_xpm_file_to_image(main->mlx, main->dir[1], &x, &y);
	//if (open(main->dir[4], O_RDONLY) == -1)
	//	ft_putendl_fd("3Error\nNO texture not found\n", 2);
	main->collactable = mlx_xpm_file_to_image(main->mlx, main->dir[4], &x, &y);
	//exit(1);
}
