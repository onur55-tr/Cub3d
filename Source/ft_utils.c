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

void	err_prnt(char *str, t_main *main)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	ft_clear(main);
}

void	ft_array_cleaner(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_variable_controller(char *line, t_main *main)
{
	char **splitted;

	splitted = ft_split(line, ' ');
	if (ft_strlen(splitted[0]) > 2 || ft_array_len(splitted) > 2)
	{
		ft_array_cleaner(splitted);
		err_prnt("Wrong direction parameter", main);
	}
	ft_array_cleaner(splitted);
	return (1);
}

char	*ft_new_strtrim(const char *line, char *side, t_main *main)
{
	char	*path;

	if (side != NULL)
		err_prnt("Wrong direction parameter", main);
	while ((ft_isalpha(*line) || ft_isspace(*line)) && *line != '.')
		++line;
	path = ft_strtrim(line, " \n");
	if (open(path, O_RDONLY) == -1)
		err_prnt("Missing texture file", main);
	return (path);

}
