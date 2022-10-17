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
# define TWO_PI 6.28318530717958647692
# define FOV_ANGLE (60 * (PI / 180))
# define NUM_RAYS 640
# define TILE_SIZE 64
# define MINIMAP_SCALE_FACTOR 0.2
# define NUM_TEXTURES 5
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define NUM_SPRITES 3
# define SPRITE_SIZE 64
# define NUM_ROWS 13
# define NUM_COLS 20
# define MAP_WIDTH (NUM_COLS * TILE_SIZE)
# define MAP_HEIGHT (NUM_ROWS * TILE_SIZE)
# define STRAFE_SPEED 5
# define TURN_SPEED 3 * (PI / 180)
# define MOVE_SPEED 5
# define MINIMAP_SCALE_FACTOR 0.2

typedef struct s_img
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	void	*s;
	void	*screen;
	int 	*no_data;
	int 	*so_data;
	int 	*we_data;
	int 	*ea_data;
	int 	*s_data;
	int		*screen_data;
}				t_img;

typedef struct	s_main
{
	void	*mlx;
	void	*win;
	int 	r[2];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f[3];
	int		c[3];
	int		x;
	int		y;
	int 	bpp;
	int 	size_line;
	int 	endian;
	char	**map;
	t_img	*img;
}				t_main;

#endif //CUB3D_H
