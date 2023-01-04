/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:37:07 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 20:37:07 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/cub3d.h"

void	set_textures_util(t_game *game, char **tmp, int dir)
{
	int	width;
	int	height;

	game->image[dir].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
		tmp[1], &width, &height);
	if (!game->image[dir].img_ptr)
		exit_with_error("Error\nXpm File Does Not Exist\n");
}

void	set_next_line(int fd, char **out_line)
{
	free(*out_line);
	*out_line = get_next_line(fd);
}

void	set_bit_flag(int index, int *result)
{
	int	i;
	int	bit_pos;

	if (index == 0)
	{
		*result |= 1;
	}
	else
	{
		i = 0;
		bit_pos = 1;
		while (i < index)
		{
			bit_pos *= 2;
			i++;
		}
		*result |= bit_pos;
	}
}
