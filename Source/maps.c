//
// Created by Onur Dursun on 10/24/22.
//

#include "cub3d.h"

static char	*ft_delchar(const char *str, t_main *main)
{
	int i;
	char *new;

	i = -1;
	while (str[++i])
		if(ft_isspace_tab(str[i]))
			err_prnt("Wrong map char", main);
	new = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	i = -1;
	while (str[++i])
		new[i] = str[i];
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
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "NO", 2) && ft_variable_controller(line, main)) {
			main->dir[0] = ft_new_strtrim(line, main->dir[0], main);
			printf("%s_\n", main->dir[0]);
		}
		if (!ft_strncmp(line, "SO", 2) && ft_variable_controller(line, main)) {
			main->dir[1] = ft_new_strtrim(line, main->dir[1], main);
			printf("%s_\n", main->dir[1]);
		}
		if (!ft_strncmp(line, "WE", 2) && ft_variable_controller(line, main)) {
			main->dir[2] = ft_new_strtrim(line, main->dir[2], main);
			printf("%s_\n", main->dir[2]);
		}
		if (!ft_strncmp(line, "EA", 2) && ft_variable_controller(line, main)) {
			main->dir[3] = ft_new_strtrim(line, main->dir[3], main);
			printf("%s_\n", main->dir[3]);
		}
		if (line[0] == 'S' && !ft_isalnum(line[1])) {
			main->dir[4] = ft_new_strtrim(line, main->dir[4], main);
			printf("%s_\n", main->dir[4]);
		}

		if (line[0] == 'F' && !ft_isalnum(line[1]))
		{
			main->f[0] = ft_rgb_num_check(ft_atoi(line + 2), main);
			main->f[1] = ft_rgb_num_check(ft_atoi(line + 6), main);
			main->f[2] = ft_rgb_num_check(ft_atoi(line + 10), main);
		}
		if (line[0] == 'C' && !ft_isalnum(line[1]))
		{
			main->c[0] = ft_rgb_num_check(ft_atoi(line + 2), main);
			main->c[1] = ft_rgb_num_check(ft_atoi(line + 6), main);
			main->c[2] = ft_rgb_num_check(ft_atoi(line + 10), main);
		}
		if (line[0] == '1')
			main->map[i++] = ft_delchar(line, main);
		if (*line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	main->dir[5] = NULL;
	main->map[i] = NULL;
	close(fd);
	ft_maps_control(main);
	return ((void *)1);
}
