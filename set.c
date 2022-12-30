/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:37:10 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 20:50:35 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/cub3d.h"

void	set_map(t_game *game, t_tmp *tmp)
{
	t_node	*node;

	node = tmp->head->next;
	game->map = (char *)malloc(sizeof(char) * (tmp->row * tmp->max_col + 1));
	game->row = tmp->row;
	game->col = tmp->max_col;
	while (node != tmp->tail)
	{
		game->map = ft_strjoin(game->map, node->line);
		node = node->next;
	}
}

void	set_textures(t_game *game, char *tmp_line)
{
	char	**tmp;

	tmp = ft_split(tmp_line, ' ');
	if (!ft_strncmp(tmp[0], "NO", 2))
		set_textures_util(game, tmp, NO);
	else if (!ft_strncmp(tmp[0], "WE", 2))
		set_textures_util(game, tmp, WE);
	else if (!ft_strncmp(tmp[0], "EA", 2))
		set_textures_util(game, tmp, EA);
	else if (!ft_strncmp(tmp[0], "SO", 2))
		set_textures_util(game, tmp, SO);
	else
		exit_with_error("Error\nNot Proper Direction\n");
	free_str(tmp, 2);
}

void	set_color(int *dir, char **color_arr)
{
	int	color;

	color = 0;
	if (check_color(color_arr))
		exit_with_error("Error\nRGB Error\n");
	while (*color_arr != NULL)
	{
		*dir <<= 8;
		color = ft_atoi(*color_arr);
		*dir |= color;
		color_arr++;
	}
}

void	set_floor_ceiling(t_game *game, char *tmp_line)
{
	char	**div_dir;
	char	**color_arr;

	div_dir = ft_split(tmp_line, ' ');
	color_arr = ft_split(div_dir[1], ',');
	if (!ft_strncmp(div_dir[0], "F", 1))
		set_color(&game->floor, color_arr);
	else if (!ft_strncmp(div_dir[0], "C", 1))
		set_color(&game->ceil, color_arr);
	else
		exit_with_error("Error\nWrong Argument");
}

void	set_vec(t_vec *vec, char dir)
{
	if (dir == 'N' || dir == 'S')
	{
		vec->d_x = 0;
		vec->w_y = 0;
		vec->d_y = -1;
		vec->w_x = 0.66;
		if (dir == 'S')
		{
			vec->d_y = 1;
			vec->w_x = -0.66;
		}
	}
	else if (dir == 'W' || dir == 'E')
	{
		vec->d_y = 0;
		vec->w_x = 0;
		vec->d_x = 1;
		vec->w_y = 0.66;
		if (dir == 'W')
		{
			vec->d_x = -1;
			vec->w_y = -0.66;
		}
	}
}
