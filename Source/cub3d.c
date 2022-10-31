#include "cub3d.h"

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
int ft_array_len(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_open_window(t_main *main, char *av)
{
	main = ft_calloc(sizeof(t_main), 1);
	main->mx = 300;
	main->my=300;
	main->angle = 270;
	main->img = ft_calloc(1, sizeof(t_img));
	if (!read_file(main, av))
		exit (1);
	main->mlx = mlx_init();
	main->win = mlx_new_window(main->mlx, (int)(ft_strlen(main->map[0]) - 1) *64,
			ft_array_len(main->map) * 64, "THE FUCKING GAME");
	get_image(main);
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