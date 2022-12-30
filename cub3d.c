#include "header/cub3d.h"

int	finish_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit(1);
}

/*
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
*/
void	set_images(t_game *game)
{
	/* 
	줄 너무 길어서 변수 수정 필요 
	*/
	game->image[BUF].img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->image[BUF].img_data = (int *)mlx_get_data_addr(game->image[BUF].img_ptr, &game->image[BUF].bits, &game->image[BUF].line_size, &game->image[BUF].endien);
	game->image[NO].img_data = (int *)mlx_get_data_addr(game->image[NO].img_ptr, &game->image[NO].bits, &game->image[NO].line_size, &game->image[NO].endien);
	game->image[SO].img_data = (int *)mlx_get_data_addr(game->image[SO].img_ptr, &game->image[SO].bits, &game->image[SO].line_size, &game->image[SO].endien);
	game->image[WE].img_data = (int *)mlx_get_data_addr(game->image[WE].img_ptr, &game->image[WE].bits, &game->image[WE].line_size, &game->image[WE].endien);
	game->image[EA].img_data = (int *)mlx_get_data_addr(game->image[EA].img_ptr, &game->image[EA].bits, &game->image[EA].line_size, &game->image[EA].endien);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		exit_with_error("Error\nWrong Argument!\n");
	fd = open_map(argv[1]);
	if (fd == FAIL)
		exit_with_error("Error\nFail to open file!\n");
	init_game(&game, fd);
	/*
	check_map_parsing(&game);
	*/
	set_images(&game);
	game.mlx_win = mlx_new_window(game.mlx_ptr, WIDTH, HEIGHT, "test");
	mlx_loop_hook(game.mlx_ptr, &make_view, &game);
	mlx_hook(game.mlx_win, X_EVENT_KEY_RELEASE, 0, &key_press, &game);
	mlx_hook(game.mlx_win, X_EVENT_KEY_EXIT, 0, &finish_window, &game);
	mlx_loop(game.mlx_ptr);
}
