#include "header/cub3d.h"
#include <stdio.h>

int	finish_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit(1);
}

void	check_map_parsing(t_game *game)
{
	for (int row = 0; row < game->row; row++)
	{
		for (int col = 0; col < game->col; col++)
		{
			printf("%c", game->map[row * game->col + col]);
		}
		printf("\n");
	}
	printf("\n");
	printf("col : %d row %d \n", game->col, game->row);
}

void	set_images(t_game *game)
{
	int	width = WIDTH;
	int height = HEIGHT;

    game->image[BUF].img_ptr = mlx_new_image(game->mlx_ptr, width, height);
	game->image[BUF].img_data = (int *)mlx_get_data_addr(game->image[BUF].img_ptr, &game->image[BUF].bits, &game->image[BUF].line_size, &game->image[BUF].endien);
	game->image[NO].img_data = (int *)mlx_get_data_addr(game->image[NO].img_ptr, &game->image[NO].bits, &game->image[NO].line_size, &game->image[NO].endien);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		exit_with_error("Error\nWrong Argument!\n");
	fd = open_map(argv[1]);
	if (fd == 0)
		exit_with_error("Error\nFail to open file!\n");
	init_game(&game, fd);
	check_map_parsing(&game);
	set_images(&game);
	game.mlx_win = mlx_new_window(game.mlx_ptr, WIDTH, HEIGHT, "test");
	//make_view(&game);
	mlx_loop_hook(game.mlx_ptr, &make_view, &game);
	mlx_hook(game.mlx_win, X_EVENT_KEY_RELEASE, 0, &key_press, &game);
	mlx_hook(game.mlx_win, X_EVENT_KEY_EXIT, 0, &finish_window, &game);
	mlx_loop(game.mlx_ptr);
}