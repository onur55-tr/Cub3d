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

char	*ft_new_strtrim(const char *line, t_main *main)
{
	int		i;

	i = 0;
	while (line[i])
	{
		ft_maps(&line, main);
		if (line[i] == 32 || line[i] == '\t')
			i++;
		else
			break ;
	}
	if (line[i] == '\n')
		ft_clear(main);
	//char *ret = ft_substr(line, i, ft_strlen(line) - i - 1);
	//printf("_{%s}\n", ret);
	return (ft_substr(line, i, ft_strlen(line) - i - 1));
}
