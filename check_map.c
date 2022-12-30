/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:36:18 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 21:00:15 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	check_top_bottom(char *line)
{
	size_t	index;

	index = -1;
	while (line[++index] != '\0')
		if (line[index] != ' ' && line[index] != '1')
			return (FAIL);
	return (SUCCESS);
}

int	check_side(char *line)
{
	if (line[0] == '0' || line[ft_strlen(line) - 1] == '0')
		return (FAIL);
	return (SUCCESS);
}

int	check_middle(t_node *node)
{
	size_t	index;

	index = 1;
	if (check_side(node->line))
		return (FAIL);
	while (index != ft_strlen(node->line))
	{
		if ((int)index >= node->prev->col)
			if (node->line[index] == '0')
				return (FAIL);
		if (node->line[index] == '0' && node->prev->line[index] == ' ')
			return (FAIL);
		else if (node->line[index] == ' ')
			if (node->prev->line[index] == '0' || \
			node->line[index - 1] == '0' || node->line[index + 1] == '0')
				return (FAIL);
		index++;
	}
	return (SUCCESS);
}

int	check_map(t_tmp *tmp)
{
	t_node	*node;

	node = tmp->head->next;
	if (check_top_bottom(node->line) == FAIL)
		return (FAIL);
	while (node != tmp->tail)
	{
		if (node == tmp->head->next || node == tmp->head->prev)
			if (check_top_bottom(node->line) == FAIL)
				return (FAIL);
		if (check_middle(node) == FAIL)
			return (FAIL);
		node = node->next;
	}
	return (SUCCESS);
}

int	check_2d_array(char **str, int count)
{
	int	index;

	index = 0;
	while (str[index] != NULL)
		index++;
	if (index != count)
		return (FAIL);
	return (SUCCESS);
}