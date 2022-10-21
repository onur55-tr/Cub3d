NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./minilibx -g
LIBFT = libft/libft.a
MLX = ./minilibx/libmlx.a
MLX_DIR = minilibx
GNL_DIR = gnl
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx

SRC = ./Source/cub3d.c \
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
	@make -C libft

$(MLX):
	make -C $(MLX_DIR)

run: all
	./cub3d maps/map.cub

clean:
	make clean -C libft
	make clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
