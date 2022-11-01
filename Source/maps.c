//
// Created by Onur Dursun on 10/24/22.
//

#include "cub3d.h"

static char	*ft_delchar(const char *str, char c)
{
	int i;
	int j;
	char *new;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != c)
			j++;
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
	ft_filecontrol(av, main);
	ft_contorller(av);
	line = get_next_line(fd);
	main->map = (char **)malloc(sizeof(char *) * 1000);
	main->dir = (char **)malloc(sizeof(char *) * 1000);
	while (line)
	{
	//	ft_maps(line, main);
		if (line[0] == 'N' && line[1] == 'O')
			main->dir[0] = ft_new_strtrim(line, main);
		if (line[0] == 'S' && line[1] == 'O')
			main->dir[1] = ft_new_strtrim(line, main);
		if (line[0] == 'W' && line[1] == 'E')
			main->dir[2] = ft_new_strtrim(line, main);
		if (line[0] == 'E' && line[1] == 'A')
			main->dir[3] = ft_new_strtrim(line, main);
		if (line[0] == 'S')
			main->dir[4] = ft_new_strtrim(line, main);
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
	ft_variable_controller(main);
	main->dir[5] = NULL;
	main->map[i] = NULL;
	close(fd);
	return ((void *)1);
}
