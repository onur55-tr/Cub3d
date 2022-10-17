// Created by Onur Dursun on 10/17/22.

#include "cub3d.h"
void up_color(t_main *main)
{

	int x = -1;
	int y;
	while (++x < MAP_WIDTH)
	{
		y = -1;
		while (++y < MAP_HEIGHT / 2)
			main->img->screen_data[y * MAP_WIDTH + x] = main->c[0] + (main->c[1] << 8) + (main->c[2] << 16);
	}
	mlx_put_image_to_window(main->mlx,main->win, main->img->screen, 0, 0);
}

void down_color(t_main *main)
{
	int x = 0;
	int y = MAP_HEIGHT / 2;

	printf("%d\n", main->c[0]+ (main->c[1] << 8) + (main->c[2] << 16));
	while (x < MAP_WIDTH && y < MAP_HEIGHT)
	{
		//mlx_pixel_put(main->mlx, main->win, x, y, main->f[0] + (main->f[1] << 8) + (main->f[2] << 16));
		main->img->screen_data[y * MAP_WIDTH + x] = main->f[0] + (main->f[1] << 8) + (main->f[2] << 16);
		x++;
		if (x == MAP_WIDTH)
		{
			y++;
			x = 0;
		}
	}
	mlx_put_image_to_window(main->mlx,main->win, main->img->screen, 0, 0);
}

int	close_frame(t_main	*main)
{
	mlx_clear_window(main->mlx, main->win);
	exit(0);
	return (0);
}

void	init_var(t_main	*main)
{
	main->img = ft_calloc(1, sizeof(t_img));
	main->img->no = mlx_xpm_file_to_image(main->mlx, main->no, &main->x, &main->y);
	main->img->so = mlx_xpm_file_to_image(main->mlx, main->so, &main->x, &main->y);
	main->img->we = mlx_xpm_file_to_image(main->mlx, main->we, &main->x, &main->y);
	main->img->ea = mlx_xpm_file_to_image(main->mlx, main->ea, &main->x, &main->y);
	main->img->s = mlx_xpm_file_to_image(main->mlx, main->s, &main->x, &main->y);
	main->img->screen = mlx_new_image(main->mlx, main->r[0], main->r[1]);
	main->img->no_data = (int *)mlx_get_data_addr(main->img->no, &main->bpp, &main->size_line, &main->endian);
	main->img->so_data = (int *)mlx_get_data_addr(main->img->so , &main->bpp, &main->size_line, &main->endian);
	main->img->we_data = (int *)mlx_get_data_addr(main->img->we, &main->bpp, &main->size_line, &main->endian);
	main->img->ea_data = (int *)mlx_get_data_addr(main->img->ea, &main->bpp, &main->size_line, &main->endian);
	main->img->s_data = (int *)mlx_get_data_addr(main->img->s, &main->bpp, &main->size_line, &main->endian);
	main->img->screen_data = (int *)mlx_get_data_addr(main->img->screen, &main->bpp, &main->size_line, &main->endian);
}

void	read_file(t_main *main, char *av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	main->map = (char **)malloc(sizeof(char *) * 1000);
	while (line)
	{
		if (line[0] == 'R')
		{
			main->r[0] = ft_atoi(line + 2);
			main->r[1] = ft_atoi(line + 7);
		}
		if (line[0] == 'N' && line[1] == 'O')
			main->no = ft_strtrim(ft_strdup(line + 3), "\n");
		if (line[0] == 'S' && line[1] == 'O')
			main->so = ft_strtrim(ft_strdup(line + 3), "\n");
		if (line[0] == 'W' && line[1] == 'E')
			main->we = ft_strtrim(ft_strdup(line + 3), "\n");
		if (line[0] == 'E' && line[1] == 'A')
			main->ea = ft_strtrim(ft_strdup(line + 3), "\n");
		if (line[0] == 'S' && line[1] == ' ')
			main->s = ft_strtrim(ft_strdup(line + 2), "\n");
		if (line[0] == 'F')
		{
			main->f[0] = ft_atoi(line + 2);
			main->f[1] = ft_atoi(line + 6);
			main->f[2] = ft_atoi(line + 10);
		}
		if (line[0] == 'C')
		{
			main->c[0] = ft_atoi(line + 2);
			main->c[1] = ft_atoi(line + 6);
			main->c[2] = ft_atoi(line + 10);
		}
		if (line[0] == '1')
			main->map[i++] = ft_strdup(line);
		if (*line)
			free(line);
		line = get_next_line(fd);
	}
	main->map[i] = NULL;
	init_var(main);
}

void draw_map(t_main *main)
{
	up_color(main);
	down_color(main);
}

int	walk(int keycode, t_main *main)
{
	if (keycode == 53)
		close_frame(main);
	return (0);
}

int main(int ac, char **av)
{
	t_main	main;

	if (ac == 2)
	{
		main.mlx = mlx_init();
		read_file(&main, av[1]);
		main.win = mlx_new_window(main.mlx, main.r[0], main.r[1], "Cub3d");
		draw_map(&main);
		mlx_hook(main.win, 2, (1L << 0), walk, &main);
		mlx_hook(main.win, 17, 0, close_frame, &main);
		mlx_loop(main.mlx);
	}
	else
		printf("Error: Wrong number of arguments.\n");
	return (0);
}
