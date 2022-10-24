NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./minilibx  -fsanitize=address -g
LIBFT = libft/libft.a
MLX = ./minilibx/libmlx.a
MLX_DIR = minilibx
RM = rm -rf
GNL_DIR = gnl
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx

SRC = ./Source/cub3d.c \
 		./Source/movement.c \
 		./Source/render.c \
 		./Source/maps.c \
 		./Source/get_image.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(GNL_DIR) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(LIBFT) $(MLX) $(OBJ)

$(GNL_DIR):
	@if [ ! -d "gnl" ]; then git clone https://github.com/onur55-tr/Gnl.git gnl; fi

$(LIBFT):
	@if [ ! -d "libft" ]; then git clone https://github.com/onur55-tr/Libft.git libft; fi
	@if [ ! -f $(LIBFT) ]; then make -C libft; fi

$(MLX):
	@if [[ ! -d $(MLX_DIR) ]]; then \
  		curl -O https://projects.intra.42.fr/uploads/document/document/9232/minilibx_opengl.tgz; \
		gunzip -c minilibx_opengl.tgz | tar xopf -; \
		$(RM) minilibx_opengl.tgz; \
		mv minilibx_opengl_20191021 minilibx; fi
	@if [[ -d $(MLX_DIR) ]]; then make -C $(MLX_DIR); fi

run: all
	./cub3d maps/map.cub

clean:
	@if [[ -d "libft" ]]; then make -C libft clean; fi
	@if [[ -d $(MLX_DIR) ]]; then make clean -C $(MLX_DIR); fi
	$(RM) $(OBJ)

fclean: clean
	@if [[ -f $(NAME) ]]; then $(RM) $(NAME); fi
	@if [[ -d $(GNL_DIR) ]]; then $(RM) gnl; fi
	@if [[ -d "libft" ]]; then $(RM) libft; fi
	@if [[ -d $(MLX_DIR) ]]; then $(RM) $(MLX_DIR); fi

re: fclean all

.PHONY: all clean fclean re
