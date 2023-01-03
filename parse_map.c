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
	int		flag;
	int		is_component;
	int		row;
	int		length;
	int		is_frist_line;

	row = 0;
	flag = 0;
	is_component = FAIL;
	is_frist_line = FAIL;
	tmp_line = get_next_line(fd);
	while (tmp_line != NULL)
	{
		length = ft_strlen(tmp_line);
		if (tmp_line[length - 1] == '\n')
		tmp_line[length - 1] = '\0';
		if (is_texture(tmp_line, &flag) == SUCCESS)
			set_textures(game, tmp_line);
		else if (is_background(tmp_line, &flag) == SUCCESS)
			set_floor_ceiling(game, tmp_line);
		else if (check_flag(&flag, COMPONENT_SIZE) == SUCCESS \
		&& check_map_content(tmp_line) == SUCCESS && tmp_line[0] != '\0')
		{
			set_tmp(tmp, tmp_line, &row);
			is_component = SUCCESS;
			is_frist_line = SUCCESS;
		}
		else if (length != 1 || tmp_line[0] != '\0' \
		|| (is_frist_line == SUCCESS && tmp_line[0] == '\0'))
		{
			exit_with_error("Error\nWrong Map Component!\n");
		}
		set_next_line(fd, &tmp_line);
	}
	free(tmp_line);
	close(fd);
	if (is_component == FAIL)
		exit_with_error("Error\nWrong Map Component!\n");
	get_max_col(tmp);
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
