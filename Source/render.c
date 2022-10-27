// Created by Onur Dursun on 10/24/22.

#include "cub3d.h"
static	int color_bitwise(int r, int g, int b)
{
	int rgb;

	rgb = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (rgb);
}

static void	up_color(t_main *main)
{

	int x;
	int y;

	x = -1;
	while (++x < main->r[0])
	{
		y = -1;
		while (++y < main->r[1] / 2)
			main->img->screen_data[y * main->r[0] + x] = color_bitwise(main->c[0], main->c[1], main->c[2]);
	}
	mlx_put_image_to_window(main->mlx,main->win, main->img->screen, 0, 0);
}

static void down_color(t_main *main)
{
	int px;
	int py;

	px = -1;
	while (++px < (int)(ft_strlen(main->map[0]) - 1) * 64)
	{
		py = -1;
		while (++py < (ft_array_len(main->map) * 64))
			main->img->screen_data[py * main->r[1] + px] = color_bitwise(main->f[0], main->f[1], main->f[2]);
	}
	mlx_put_image_to_window(main->mlx,main->win, main->img->screen, 0, 0);
}

void	put_player(t_main *main, int px, int py)
{
	//printf("%d %d\n", px, py);
	(void)px;
	(void)py;
	int i;
	i = -1;
	while (++i < 60) {
		mlx_pixel_put(main->mlx, main->win, main->mx + (i * cos((main->angle) * (PI / 180))), main->my + (i * sin((main->angle) * (PI / 180))), 0xff0000);
		mlx_pixel_put(main->mlx, main->win, main->mx + (i * cos((main->angle + 30) * (PI / 180))), main->my + (i * sin((main->angle + 30) * (PI / 180))), 0x00ff00);
		mlx_pixel_put(main->mlx, main->win, main->mx + (i * cos((main->angle - 30) * (PI / 180))), main->my + (i * sin((main->angle - 30) * (PI / 180))), 0xff);
	}
}

void	render_map(t_main *main)
{
	int	x;
	int y;
	int i;
	int j;

	x = 0;
	y = 0;
	i = -1;
	j = -1;
	while(main->map[++i])
	{
		while (main->map[i][++j])
		{
			if(main->map[i][j] == '1')
				mlx_put_image_to_window(main->mlx, main->win, main->block, x, y);
			if (main->map[i][j] == '2')
				mlx_put_image_to_window(main->mlx, main->win, main->collactable, x, y);
			x += 64;
		}
		y += 64;
		j = -1;
		x = 0;
	}
	put_player(main, x, y);
}

void	ft_draw(t_main *main)
{
	main->img->screen = mlx_new_image(main->mlx, main->r[0], main->r[1]);
	main->img->screen_data = (int *)mlx_get_data_addr(main->img->screen, &main->img->bpp,
													  &main->img->size_line, &main->img->endian);

	down_color(main);
	up_color(main);
	render_map(main);
}

