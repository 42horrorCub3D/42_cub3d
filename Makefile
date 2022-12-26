NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Wall -g3

LIB_DIR = ./libft
LIB = ./libft/libft.a

MLX_DIR = ./mlx
MLX = -L./$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

GNL = gnl/get_next_line.c

SRCS = check_image.c check_map.c cub3d.c error.c init.c make_view.c \
	move.c parse_map.c ray_casting.c set.c

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIB_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB) $(MLX)
	@echo "📦 Here is cub3D 📦"

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@echo "❌ Clean cub3D ❌"
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all