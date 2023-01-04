/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:36:57 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 20:44:55 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"
#include <stdio.h>
#include <string.h>
void	set_tmp(t_tmp *tmp, char *tmp_line, int *row)
{
	ft_lstadd_back(tmp, tmp_line, ft_strlen(tmp_line));
	tmp->row = ++(*row);
}

void	fill_map(t_tmp *tmp)
{
	t_node	*node;

	node = tmp->tail->prev;
	while (node != tmp->head)
	{
		if (node->col < tmp->max_col)
			while ((int)ft_strlen(node->line) < tmp->max_col)
				node->line = ft_strjoin(node->line, " ");
		node = node->prev;
	}
}

void	get_max_col(t_tmp *tmp)
{
	int		max;
	t_node	*node;

	node = tmp->head->next;
	max = 0;
	while (node != tmp->tail)
	{
		if (node->col > max)
			max = node->col;
		node = node->next;
	}
	tmp->max_col = max;
}

void	get_map(t_tmp *tmp, t_game *game, int fd)
{
	char	*tmp_line;
	int		row;

	row = 0;
	tmp_line = get_next_line(fd);
	while (tmp_line != NULL)
	{
		if (tmp_line[ft_strlen(tmp_line) - 1] == '\n')
			tmp_line[ft_strlen(tmp_line) - 1] = '\0';
		if (is_texture(tmp_line, &tmp->flag) == SUCCESS)
			set_textures(game, tmp_line);
		else if (is_background(tmp_line, &tmp->flag) == SUCCESS)
			set_floor_ceiling(game, tmp_line);
		else if (check_flag(&tmp->flag, COMPONENT_SIZE) == SUCCESS && check_map_content(tmp_line) == SUCCESS)
		{
			set_tmp(tmp, tmp_line, &row);
			tmp->is_component = SUCCESS;
		}
		else if (ft_strlen(tmp_line) != 0 || tmp_line[0] != '\0')
		{
			exit_with_error("Error\nWrong Map Component! 1\n");
		}
		set_next_line(fd, &tmp_line);
	}
	free(tmp_line);
	if (tmp->is_component == FAIL)
		exit_with_error("Error\nWrong Map Component! 2\n");
}

int	open_map(const char *file)
{
	int		fd;
	size_t	len;

	len = ft_strlen(file);
	if (len <= 4)
		return (FAIL);
	if (file[len - 1] != 'b' || file[len - 2] != 'u')
		return (FAIL);
	if (file[len - 3] != 'c' || file[len - 4] != '.')
		return (FAIL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (FAIL);
	return (fd);
}
