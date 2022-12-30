/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:36:37 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 20:36:39 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/cub3d.h"

int	make_view(t_game *game)
{
	int		x;
	t_ray	ray;
	t_wall	wall;

	x = -1;
	draw_ceil_floor(game);
	while (++x < WIDTH)
	{
		init_ray(&ray, x, game->vec);
		init_side(&ray, game->vec);
		dda(&ray, game, x, &wall);
	}
	return (0);
}

void	draw_ceil_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				game->image[BUF].img_data[y * WIDTH + x] = game->ceil;
			else
				game->image[BUF].img_data[y * WIDTH + x] = game->floor;
			x++;
		}
		y++;
	}
}
