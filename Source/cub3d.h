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

# define key_w 13
# define key_q 12
# define key_e 14
# define key_a 0 
# define key_s 1
# define key_d 2

typedef struct s_img
{
	void	*screen;
	int		*screen_data;
	int 	bpp;
	int 	size_line;
	int 	endian;

}	t_img;


typedef struct	s_main
{
	void	*mlx;
	void	*win;
	int 	r[2];
	int		f[3];
	int 	c[3];
	int 	mx; //silin
	int 	my; // silin
	double	zoom ; //silin
	char	**dir;
	char	**map;
	void	*block; //sil
	void	*floor; //sil
	t_img	*img;
}				t_main;

int		close_frame(t_main *main);
int		walk(int keycode, t_main *main);
void	ft_draw(t_main *main);
void	*read_file(t_main *main, char *av);
void	render_map(t_main *main);
void	get_image(t_main *main);
void	put_player(t_main *main, int px, int py);
int ft_array_len(char **str);

#endif //CUB3D_H
