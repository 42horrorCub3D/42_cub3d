/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:36:47 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 20:36:48 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	init_side(t_ray *ray, t_vec *vec)
{
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (vec->p_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - vec->p_x) * ray->delta_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (vec->p_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - vec->p_y) * ray->delta_y;
	}
}

void	init_ray(t_ray *ray, int x, t_vec *vec)
{
	ray->cam = 2 * x / (double)WIDTH - 1;
	ray->ray_x = vec->d_x + (vec->w_x * ray->cam);
	ray->ray_y = vec->d_y + (vec->w_y * ray->cam);
	ray->map_x = (int)vec->p_x;
	ray->map_y = (int)vec->p_y;
	ray->delta_x = fabs(1 / ray->ray_x);
	ray->delta_y = fabs(1 / ray->ray_y);
	ray->hit = 0;
}

void	init_vec(t_tmp *tmp, t_vec *vec)
{
	t_node	*node;
	size_t	index;
	char	dir;
	int		count;

	count = 0;
	node = tmp->head->next;
	while (node != tmp->tail)
	{
		index = 0;
		while (node->line[index] != '\0')
		{
			dir = node->line[index];
			if (dir == 'N' || dir == 'W' || dir == 'E' || dir == 'S')
			{
				vec->p_x = index + 0.5;
				vec->p_y = count + 0.5;
				set_vec(vec, dir);
			}
			index++;
		}
		node = node->next;
		count++;
	}
}

void	init_tmp(t_tmp *tmp)
{
	tmp->head = (t_node *)malloc(sizeof(t_node));
	tmp->head->line = ft_strdup("");
	tmp->head->col = 0;
	tmp->tail = (t_node *)malloc(sizeof(t_node));
	tmp->tail->line = ft_strdup("");
	tmp->tail->col = 0;
	tmp->head->next = tmp->tail;
	tmp->head->prev = tmp->head;
	tmp->tail->next = tmp->tail;
	tmp->tail->prev = tmp->head;
	tmp->is_component = FAIL;
	tmp->flag = 0;
	tmp->user_count = 0;
}

void	init_game(t_game *game, int fd)
{
	t_tmp	*tmp;

	tmp = (t_tmp *)malloc(sizeof(t_tmp));
	game->mlx_ptr = mlx_init();
	game->vec = (t_vec *)malloc(sizeof(t_vec));
	game->ceil = 0;
	game->floor = 0;
	init_tmp(tmp);
	get_map(tmp, game, fd);
	get_max_col(tmp);
	if (check_map(tmp) == FAIL)
		exit_with_error("Error\nMap check failed\n");
	fill_map(tmp);
	init_vec(tmp, game->vec);
	set_map(game, tmp);
	free_tmp(tmp);
	close(fd);
}
