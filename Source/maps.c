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
	while (line)
	{
	//	ft_maps(line, main);
		if (ft_strnstr(line, "NO", ft_strlen(line)))
			main->dir[0] = ft_new_strtrim(line, main->dir[0], main);
		if (ft_strnstr(line, "SO", ft_strlen(line)))
			main->dir[1] = ft_new_strtrim(line, main->dir[1], main);
		if (ft_strnstr(line, "WE", ft_strlen(line)))
			main->dir[2] = ft_new_strtrim(line, main->dir[2], main);
		if (ft_strnstr(line, "EA", ft_strlen(line)))
			main->dir[3] = ft_new_strtrim(line, main->dir[3], main);
		if (line[0] == 'S' && !ft_isalnum(line[1]))
			main->dir[4] = ft_new_strtrim(line, main->dir[4], main);
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
			main->map[i++] = ft_delchar(line, ' ');
		if (*line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	main->dir[5] = NULL;
	main->map[i] = NULL;
	close(fd);
	ft_variable_controller(main);
	return ((void *)1);
}
