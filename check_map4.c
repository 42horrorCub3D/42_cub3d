/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:06:07 by minslee           #+#    #+#             */
/*   Updated: 2023/01/04 16:06:08 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	check_player_pos(t_node *node, int index)
{
	if (node->line[index] == 'N' || node->line[index] == 'S' || \
	node->line[index] == 'E' || node->line[index] == 'W')
	{
		if (index + 1 < (int)ft_strlen(node->line))
		{
			if (node->line[index - 1] == ' ' || node->line[index + 1] == ' ' || \
			node->prev->line[index] == ' ')
				return (FAIL);
		}
	}
	return (SUCCESS);
}

int	check_player_exist(char ch)
{
	if (ch == 'N' || ch == 'E' || ch == 'W' || ch == 'S')
		return (SUCCESS);
	return (FAIL);
}
