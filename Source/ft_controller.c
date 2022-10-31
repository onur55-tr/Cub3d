// Created by Onur Dursun on 10/31/22.

#include "cub3d.h"

static int	ft_isspace_tab(char *str)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	if (!*str)
		return (0);
	while (str[++i])
		if (str[i] != 32 || !(str[i] >= 9 && str[i] <= 13) || str[i] != '\n')
			flag++;
	return (flag);
}

int	ft_contorller(char *av)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_isspace_tab(line))
			continue ;
		if (line[i] == 'N' && line[i + 1] == 'O')
			i++;
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	return (0);
}
