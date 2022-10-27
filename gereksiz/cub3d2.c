// Created by Onur Dursun on 10/17/22.

#include "cub3d2.h"

/*void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	*dst;

	dst = img->screen_data + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_rect(t_main *main, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			my_mlx_pixel_put(main->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int render_map(t_main *main)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	y = 0;
	while (i < NUM_ROWS)
	{
		j = 0;
		x = 0;
		while (j < NUM_COLS)
		{
			if (main->map[i][j] == '1')
				draw_rect(main, x, y, 0x00FF0000);
			else if (main->map[i][j] == '2')
				draw_rect(main, x, y, 0x0000FF00);
			else if (main->map[i][j] == '0')
				draw_rect(main, x, y, 0x00000000);
			else if (main->map[i][j] == 'N')
				draw_rect(main, x, y, 0x000000FF);
			else if (main->map[i][j] == 'S')
				draw_rect(main, x, y, 0x000000FF);
			else if (main->map[i][j] == 'E')
				draw_rect(main, x, y, 0x000000FF);
			else if (main->map[i][j] == 'W')
				draw_rect(main, x, y, 0x000000FF);
			j++;
			x += TILE_SIZE;
		}
		i++;
		y += TILE_SIZE;
	}
	return (0);
}*/

void	put_player(t_main *main, int px, int py)
{
	//printf("%d %d\n", px, py);
	int i;
	int	x;
	int y;

	x = main->r[0] / 2;
	y = main->r[1] / 2;
	main->angle  = 60;
 * i = 0;
	while (++px < (int)(ft_strlen(main->map[0]) - 1) * 64)
	{
		py = -1;
		while (++py < (ft_array_len(main->map) * 64))
		{
			if ((px > x -1  + main->mx && px <  x + 1 + main->mx)
			 &&  (py > y - 20 + main->my && py <  y + 20 + main->my))
				mlx_pixel_put(main->mlx, main->win, px, py,  0xff);
			if ((px > x -1  + main->mx && px <  x + 1 + main->mx)
				&&  (py > y - 40 + main->my && py <  y + 40 + main->my))
			{
				mlx_pixel_put(main->mlx, main->win, px - i, py + main->angle - i,  0xff);
				mlx_pixel_put(main->mlx, main->win, px + i, py + main->angle - i,  0xff);
				i++;
				main->angle--;
			}
		}
	}
}

int ft_arraylen(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	render_map(t_main *main)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	y = 0;
	//for (int a = 0; main->map[a]; a++)
	//	printf("%s", main->map[a]);
	while (i < ft_arraylen(main->map))
	{
		j = 0;
		x = 0;
		while (j < (int)ft_strlen(main->map[i]))
		{
			if (main->map[i][j] == '1')
				mlx_put_image_to_window(main->mlx, main->win, main->img->no, x, y);
			else if (main->map[i][j] == '2')
				mlx_put_image_to_window(main->mlx, main->win, main->img->s, x, y);
			else if (main->map[i][j] == 'S')
				mlx_put_image_to_window(main->mlx, main->win, main->img->so, x, y);
			else if (main->map[i][j] == 'E')
				mlx_put_image_to_window(main->mlx, main->win, main->img->ea, x, y);
			else if (main->map[i][j] == 'W')
				mlx_put_image_to_window(main->mlx, main->win, main->img->we, x, y);
			else if (main->map[i][j] == 'N')
				mlx_put_image_to_window(main->mlx, main->win, main->img->no, x, y);
			x += 64;
			j++;
		}
		i++;
		y += 64;
	}
}


void up_color(t_main *main)
{

	int x = -1;
	int y;
	while (++x < main->r[0])
	{
		y = -1;
		while (++y < main->r[1] / 2)
			main->img->screen_data[y * main->r[0] + x] = ((main->c[0] & 0xff) << 16) + \
			((main->c[1] & 0xff) << 8) + (main->c[2] & 0xff);
	}
	mlx_put_image_to_window(main->mlx,main->win, main->img->screen, 0, 0);
}

void down_color(t_main *main)
{
	int x;
	int y = main->r[0] / 2;

	while (y < main->r[0]){

		x = -1;
		while (++x < main->r[1])
			main->img->screen_data[y * main->r[1] + x] =  ((main->f[0] & 0xff) << 16) + \
			((main->f[1] & 0xff) << 8) + (main->f[2] & 0xff);
		y++;

	}
	mlx_put_image_to_window(main->mlx,main->win, main->img->screen, 0, 0);
}

int	close_frame(t_main	*main)
{
	mlx_destroy_window(main->mlx, main->win);
	free(main->no);
	free(main->so);
	free(main->we);
	free(main->ea);
	free(main->s);
	//system("leaks cub3d");
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
	main->img->main = (int *)mlx_get_data_addr(main->img->s, &main->bpp, &main->size_line, &main->endian);
	main->img->screen_data = (int *)mlx_get_data_addr(main->img->screen, &main->bpp, &main->size_line, &main->endian);
}

void ft_newsplit(char **str, char *line)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			str[j][k] = '\0';
			j++;
			k = 0;
		}
		else
		{
			str[j][k] = line[i];
			k++;
		}
		i++;
	}
	str[j][k] = '\0';
}

char	*ft_delchar(char *str, char c)
{
	int i;
	int j;
	char *new;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
			j++;
		i++;
	}
	new = malloc(sizeof(char) * (j + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
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
			main->no = ft_strtrim(line + 3, "\n");
		if (line[0] == 'S' && line[1] == 'O')
			main->so = ft_strtrim(line + 3, "\n");
		if (line[0] == 'W' && line[1] == 'E')
			main->we = ft_strtrim(line + 3, "\n");
		if (line[0] == 'E' && line[1] == 'A')
			main->ea = ft_strtrim(line + 3, "\n");
		if (line[0] == 'S' && line[1] == ' ')
			main->s = ft_strtrim(line + 2, "\n");
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
			main->map[i++] = ft_delchar(line, ' ');
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
	render_map(main);
}

int	walk(int keycode, t_main *main)
{
	if (keycode == 53)
		close_frame(main);
	if (keycode == 13) // ileri tuşu
	{
		if (!main->map[(int)(main->posX + main->dirX * main->moveSpeed)][(int)(main->posY)])
			main->posX += main->dirX * main->moveSpeed;
		if (!main->map[(int)(main->posX)][(int)(main->posY + main->dirY * main->moveSpeed)])
			main->posY += main->dirY * main->moveSpeed;
	}
	if (keycode == 1) // geri tuşu
	{
		if (!main->map[(int)(main->posX - main->dirX * main->moveSpeed)][(int)(main->posY)])
			main->posX -= main->dirX * main->moveSpeed;
		if (!main->map[(int)(main->posX)][(int)(main->posY - main->dirY * main->moveSpeed)])
			main->posY -= main->dirY * main->moveSpeed;
	}
	if (keycode == 124) //camera sağ
	{
		double oldDirX = main->dirX;
		main->dirX = main->dirX * cos(-main->rotSpeed) - main->dirY * sin(-main->rotSpeed);
		main->dirY = oldDirX * sin(-main->rotSpeed) + main->dirY * cos(-main->rotSpeed);
		double oldPlaneX = main->planeX;
		main->planeX = main->planeX * cos(-main->rotSpeed) - main->planeY * sin(-main->rotSpeed);
		main->planeY = oldPlaneX * sin(-main->rotSpeed) + main->planeY * cos(-main->rotSpeed);
	}
	if (keycode == 123) //camera sol
	{
		double oldDirX = main->dirX;
		main->dirX = main->dirX * cos(main->rotSpeed) - main->dirY * sin(main->rotSpeed);
		main->dirY = oldDirX * sin(main->rotSpeed) + main->dirY * cos(main->rotSpeed);
		double oldPlaneX = main->planeX;
		main->planeX = main->planeX * cos(main->rotSpeed) - main->planeY * sin(main->rotSpeed);
		main->planeY = oldPlaneX * sin(main->rotSpeed) + main->planeY * cos(main->rotSpeed);
	}
	mlx_clear_window(main->mlx, main->win);
	up_color(main);
	down_color(main);
	render_map(main);
	return (0);
}

int main(int ac, char **av)
{
	t_main	main;

	if (ac == 2)
	{
		main.posX = 12;
		main.posY = 5;
		main.dirX = -1;
		main.dirY = 0;
		main.planeX = 0;
		main.planeY = 0.66;
		main.moveSpeed = 0.05;
		main.rotSpeed = 0.05;
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
