// Created by Onur Dursun on 10/31/22.

#include "cub3d.h"


void	ft_maps_control(t_main *main)
{
	if (main->dir[0] == 0 || main->dir[1] == 0 || main->dir[2] == 0 || main->dir[3] == 0
			|| main->dir[4] == 0 || main->f[0] == 0 || main->f[1] == 0 || main->f[2] == 0
			|| main->c[0] == 0 || main->c[1] == 0 || main->c[2] == 0)
	{
		ft_putstr_fd("Error\nMissing parameter", 2);
		ft_clear(main);
	}
	four_wall_control(main);
	is_wall_leaks(main);
}

int ft_rgb_num_check(int num, t_main *main)
{
	if (num >= 0 && num <= 255)
		return (num);
	ft_putstr_fd("Error\nMissing texture", 2);
	ft_clear(main);
	return (-1);
}

int	ft_isspace_tab(char c)
{
	return (c == ' ' || c == '\f' || c == '\r' || c == '\t'
			|| c == '\v');
}

void	four_wall_control(t_main *main)
{
	int i;
	int last_nbr;

	i = -1;
	while (main->map[0][++i])
		if (main->map[0][i] == '0')
			err_prnt("Wall Not Closed", main);
	last_nbr = ft_array_len(main->map) - 1;
	i = -1;
	while (main->map[last_nbr][++i])
		if (main->map[last_nbr][i] == '0')
			err_prnt("Wall Not Closed", main);
	i = -1;
	while (main->map[++i])
		if (main->map[i][0] == '0')
			err_prnt("Wall Not Closed", main);
	i = -1;
	while (main->map[++i])
	{
		last_nbr = ft_strlen(main->map[i]) - 1;
		if (main->map[i][last_nbr - 1] == '0')
			err_prnt("Wall Not Closed", main);
	}
}

void	is_wall_leaks(t_main *main)
{
	int i;
	int small;

	i = -1;
	while(main->map[++i] && main->map[i + 1])
	{
		if (ft_strlen(main->map[i]) > ft_strlen(main->map[i + 1]))
		{
			small = ft_strlen(main->map[i + 1]) -2;
			while (main->map[i][++small])
				if (main->map[i][small] == '0')
					err_prnt("Wall Not Closed Inline", main);
		}
	}
}
