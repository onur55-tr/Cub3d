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
	return ((void *)1);
}

void	ft_open_window(t_main *main, char *av)
{
	main = ft_calloc(sizeof(t_main), 1);
	if (!read_file(main, av))
		exit (1);
	main->mlx = mlx_init();
	main->win = mlx_new_window(main->mlx, 1080, 720, "THE FUCKING GAME");
}

int main(int argc, char **argv) {
	t_main main;

	if (argc != 2)
		ft_putendl_fd("Error", 2);
	else
		ft_open_window(&main, argv[1]);

}