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
	if (ft_strlen(line) > 0)
		if (line[0] == '0' || line[ft_strlen(line) - 1] == '0')
			return (FAIL);
	return (SUCCESS);
}

int	check_middle(t_node *node)
{
	size_t	index;

	index = 1;
	if (check_side(node->line) == FAIL)
		return (FAIL);
	while (index < ft_strlen(node->line))
	{
		if ((int)index >= node->prev->col)
			if (node->line[index] == '0' || \
			check_player_exist(node->line[index]))
				return (FAIL);
		if (node->line[index] == '0' && node->prev->line[index] == ' ')
			return (FAIL);
		else if (node->line[index] == ' ')
		{
			if (node->prev->line[index] == '0' || \
			node->line[index - 1] == '0' || node->line[index + 1] == '0')
				return (FAIL);
		}
		else if (check_player_pos(node, index) == FAIL)
			return (FAIL);
		index++;
	}
	return (SUCCESS);
}

int	check_map(t_tmp *tmp)
{
	t_node	*node;
	t_node	*first;
	t_node	*last;

	first = tmp->head->next;
	last = tmp->tail->prev;
	find_first_last(&first, &last);
	node = first;
	if (check_top_bottom(node->line) == FAIL)
		return (FAIL);
	if (node->line[0] == '\n' && check_nl(node, tmp) == FAIL)
		return (FAIL);
	while (node != last->next)
	{
		if (check_map_content2(node->line, tmp) == FAIL)
			return (FAIL);
		if ((node == first || node == last) && \
		check_top_bottom(node->line) == FAIL)
			return (FAIL);
		else if (check_middle(node) == FAIL)
			return (FAIL);
		node = node->next;
	}
	return (SUCCESS);
}

int	check_nl(t_node *node, t_tmp *tmp)
{
	while (node != tmp->tail)
	{
		if (ft_strncmp(node->line, "\n", 1) != 0)
			return (FAIL);
		node = node->next;
	}
	return (SUCCESS);
}
