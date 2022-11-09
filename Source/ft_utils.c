// Created by Onur Dursun on 10/31/22.

#include "cub3d.h"

void	ft_clear(t_main *main)
{
	close_frame(main);
	free(main->img);
	free(main->map);
	free(main->dir);
	free(main);
}

void	ft_filecontrol(const char *av, t_main *main)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (av[i - 1] != 'b' || av[i - 2] != 'u' || av[i - 3] != 'c'
		|| av[i - 4] != '.')
	{
		ft_putstr_fd("Error\nWrong file extension", 2);
		ft_clear(main);
	}
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
			|| c == '\v');
}

char	*ft_new_strtrim(const char *line, char *side, t_main *main)
{
	char	*path;

	if (side != NULL)
	{
		ft_putstr_fd("Error\nWrong direction parameter", 2);
		ft_clear(main);
	}
	while ((ft_isalpha(*line) || ft_isspace(*line)) && *line != '.')
		++line;
	path = ft_strtrim(line, " \n");
	if (open(path, O_RDONLY) == -1)
	{
		ft_putstr_fd("Error\nWrong texture file", 2);
		ft_clear(main);
	}
	return (path);

}
