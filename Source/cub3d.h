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

/*
#ifndef KEY_W
#  define KEY_W 13
# endif
# ifndef KEY_Q
#  define KEY_Q 12
# endif
# ifndef KEY_E
#  define KEY_E 14
# endif
# ifndef KEY_A
#  define KEY_A 0
# endif
# ifndef KEY_S
#  define KEY_S 1
# endif
# ifndef KEY_D
#  define KEY_D 2
# endif*/

typedef enum e_key
{
	/*
	KEY_W=13,
	KEY_Q=12,
	KEY_A=0,
	KEY_S=1,
	KEY_D=2
	*/
	KEY_W __attribute__((unused)) = 13,
	KEY_Q __attribute__((unused)) = 12,
	KEY_E __attribute__((unused)) = 14,
	KEY_A __attribute__((unused)) = 0,
	KEY_S __attribute__((unused)) = 1,
	KEY_D __attribute__((unused)) = 2
}	t_key;

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
	void	*collactable;
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
