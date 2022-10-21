//
// Created by Onur Dursun on 10/17/22.
//

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define PI 3.14159265358979323846
# define TURN_SPEED 3 * (PI / 180)

typedef struct	s_main
{
	void	*mlx;
	void	*win;
	int 	r[2];
	int		f[3];
	int 	c[3];
	char	**dir;
	char	**map;
}				t_main;

#endif //CUB3D_H
