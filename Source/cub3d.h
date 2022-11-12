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
# define HEIGHT 720
# define WIDTH 1080


typedef enum e_key
{
	KEY_W __attribute__((unused)) = 13,
	//KEY_Q __attribute__((unused)) = 12,
	//KEY_E __attribute__((unused)) = 14,
	KEY_A __attribute__((unused)) = 0,
	KEY_S __attribute__((unused)) = 1,
	KEY_D __attribute__((unused)) = 2
}	t_key;

typedef struct s_var
{
	int	px;
	int	py;
	int	r_i;
	int	r_j;
	int	r_x;
	int	r_y;
	int	count_n;
	int	count_so;
	int	count_w;
	int	count_e;
	int	count_s;
	int count_f;
	int count_c;
}	t_var;

typedef struct s_img
{
	void	*screen;
	int		*screen_data;
	int		bpp;
	int		size_line;
	int		endian;

}	t_img;


typedef struct	s_main
{
	void	*mlx;
	void	*win;
	int		f[3];
	int		c[3];
	double		mx;
	double 		my;
	char	**dir;
	char	**map;
	void	*block; //sil
	void	*floor; //sil
	void	*collactable;
	int		angle;
	t_img	*img;
	t_var	*v;
	int		wal_chk_arg;
}				t_main;

int		close_frame(t_main *main);
int		walk(int keycode, t_main *main);
void	ft_draw(t_main *main);
void	*read_file(t_main *main, char *av);
void	render_map(t_main *main);
void	get_image(t_main *main);
void	put_player(t_main *main);
int		ft_array_len(char **str);
char	*ft_new_strtrim(const char *line, char *side, t_main *main);
void	ft_filecontrol(const char *av, t_main *main);
int		ft_isspace_tab(char c);
int		ft_variable_controller(char *line, t_main *main);
void	ft_clear(t_main *main);
int		ft_rgb_num_check(int num, t_main *main);
int		ft_isspace(int c);
void	ft_maps_control(t_main *main);
void	err_prnt(char *str, t_main *main);
void	four_wall_control(t_main *main);
void	is_wall_leaks(t_main *main);

#endif //CUB3D_H
