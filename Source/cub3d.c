#include "cub3d.h"

char	*ft_delchar(const char *str, char c)
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

void	ft_draw(t_main *main)
{
	main->img = ft_calloc(1, sizeof(t_img));
	main->img->screen = mlx_new_image(main->mlx, main->r[0], main->r[1]);
	main->img->screen_data = (int *)mlx_get_data_addr(main->img->screen, &main->img->bpp,
			&main->img->size_line, &main->img->endian);
	down_color(main);
	up_color(main);
}

void	*read_file(t_main *main, char *av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	main->map = (char **)malloc(sizeof(char *) * 1000);
	main->dir = (char **)malloc(sizeof(char *) * 1000);

	while (line)
	{
		if (line[0] == 'R')
		{
			main->r[0] = ft_atoi(line + 2);
			main->r[1] = ft_atoi(line + 7);
		}
		if (line[0] == 'N' && line[1] == 'O')
			main->dir[0] = ft_strtrim(line + 3, "\n");
		if (line[0] == 'S' && line[1] == 'O')
			main->dir[1] = ft_strtrim(line + 3, "\n");
		if (line[0] == 'W' && line[1] == 'E')
			main->dir[2] = ft_strtrim(line + 3, "\n");
		if (line[0] == 'E' && line[1] == 'A')
			main->dir[3] = ft_strtrim(line + 3, "\n");
		if (line[0] == 'S' && line[1] == ' ')
			main->dir[4] = ft_strtrim(line + 2, "\n");
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
	main->dir[5] = NULL;
	main->map[i] = NULL;
	close(fd);
	return ((void *)1);
}

int	close_frame(t_main *main)
{
	free(main->dir[0]);
	free(main->dir[1]);
	free(main->dir[2]);
	free(main->dir[3]);
	free(main->dir[4]);
	//system("leaks cub3d");
	mlx_destroy_window(main->mlx, main->win);
	exit(0);
	return (0);
}

int	walk(int keycode, t_main *main)
{
	if (keycode == 53)
		close_frame(main);
	mlx_clear_window(main->mlx, main->win);
	return (keycode);
}

void	ft_open_window(t_main *main, char *av)
{
	main = ft_calloc(1, sizeof(t_main));
	if (!read_file(main, av))
		exit (1);
	main->mlx = mlx_init();
	main->win = mlx_new_window(main->mlx, 1080, 720, "THE FUCKING GAME");
	ft_draw(main);
	mlx_hook(main->win, 2, (1L << 0), walk, main);
	mlx_hook(main->win, 17, 0, close_frame, main);
	mlx_loop(main->mlx);
}

int main(int argc, char **argv) {
	t_main main;

	if (argc != 2)
		ft_putendl_fd("Error", 2);
	else
		ft_open_window(&main, argv[1]);
}