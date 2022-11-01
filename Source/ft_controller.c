// Created by Onur Dursun on 10/31/22.

#include "cub3d.h"

void	ft_maps(const char **str, t_main *main)
{
	while (**str)
	{
		if (**str == 'N' && *(*str + 1) == 'O')
		{
			*str += 2;
			main->v->count_n = 1;
		}
		if (**str == 'S' && *(*str + 1) == 'O')
		{
			*str += 2;
			main->v->count_so = 1;
		}
		if (**str == 'W' && *(*str + 1) == 'E')
		{
			*str += 2;
			main->v->count_w = 1;
		}
		if (**str == 'E' && *(*str + 1) == 'A')
		{
			*str += 2;
			main->v->count_e = 1;
		}
		if (**str == 'S' && !ft_isalpha(*(*str + 1)))
		{
			*str += 1;
			main->v->count_s = 1;
		}
		else
			break ;
	}
}

void	ft_variable_controller(t_main *main)
{
	if (main->v->count_n == 0 || main->v->count_so == 0 || main->v->count_w == 0
		|| main->v->count_e == 0 || main->v->count_s == 0)
	{
		ft_putstr_fd("Error\nMissing texture", 2);
		ft_clear(main);
	}
}

int	ft_isspace_tab(const char *str)
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
