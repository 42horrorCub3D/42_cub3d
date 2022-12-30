/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:36:25 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 20:36:27 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	finish_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit(1);
}

void	set_images(t_game *game, t_image *img)
{
	img[BUF].img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	img[BUF].img_data = (int *)mlx_get_data_addr(img[BUF].img_ptr, \
		&img[BUF].bits, &img[BUF].line_size, &img[BUF].endien);
	img[NO].img_data = (int *)mlx_get_data_addr(img[NO].img_ptr, \
		&img[NO].bits, &img[NO].line_size, &img[NO].endien);
	img[SO].img_data = (int *)mlx_get_data_addr(img[SO].img_ptr, \
		&img[SO].bits, &img[SO].line_size, &img[SO].endien);
	img[WE].img_data = (int *)mlx_get_data_addr(img[WE].img_ptr, \
		&img[WE].bits, &img[WE].line_size, &img[WE].endien);
	img[EA].img_data = (int *)mlx_get_data_addr(img[EA].img_ptr, \
		&img[EA].bits, &img[EA].line_size, &img[EA].endien);
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
	set_images(&game, game.image);
	game.mlx_win = mlx_new_window(game.mlx_ptr, WIDTH, HEIGHT, "test");
	mlx_loop_hook(game.mlx_ptr, &make_view, &game);
	mlx_hook(game.mlx_win, X_EVENT_KEY_RELEASE, 0, &key_press, &game);
	mlx_hook(game.mlx_win, X_EVENT_KEY_EXIT, 0, &finish_window, &game);
	mlx_loop(game.mlx_ptr);
}
