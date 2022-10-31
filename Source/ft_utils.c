// Created by Onur Dursun on 10/31/22.

#include "cub3d.h"

void	ft_clear(t_main *main)
{
	free(main->img);
	free(main->map);
	free(main->dir);
	free(main);
	//system("leaks cub3d");
	exit(1);
}

void	ft_maps(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == 'N' && str[*i + 1] == 'O')
			*i += 2;
		else if (str[*i] == 'S' && str[*i + 1] == 'O')
			*i += 2;
		else if (str[*i] == 'W' && str[*i + 1] == 'E')
			*i += 2;
		else if (str[*i] == 'E' && str[*i + 1] == 'A')
			*i += 2;
		else if (str[*i] == 'S')
			*i += 1;
		else
			break ;
	}
}

char	*ft_new_strtrim(char *line, t_main *main)
{
	int		i;
	//char	*ret;
	i = 0;
	while (line[i])
	{
		ft_maps(line, &i);
		if (line[i] == 32 || line[i] == 9)
			i++;
		else
			break ;
	}
	//printf("%s\n", line);
	if (line[i] == '\n')
		ft_clear(main);
	//ret = ft_substr(line, i, ft_strlen(line) - i - 1);
	//printf("_{%s}\n", ret);
	return (ft_substr(line, i, ft_strlen(line) - i - 1));
}
