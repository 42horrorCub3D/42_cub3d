/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:56:41 by minslee           #+#    #+#             */
/*   Updated: 2023/01/04 14:56:56 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

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

int	check_map_content(char *line)
{
	size_t	index;
	char	*content;
	int		j;
	int		is_content;

	index = -1;
	content = " 10NSWE";
	is_content = FAIL;
	while (line[++index] != '\0')
	{
		j = -1;
		while (++j < 7)
		{
			if (line[index] == content[j])
			{
				is_content = SUCCESS;
				break ;
			}
		}
		if (is_content == FAIL)
			return (FAIL);
		is_content = FAIL;
	}
	return (SUCCESS);
}

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
