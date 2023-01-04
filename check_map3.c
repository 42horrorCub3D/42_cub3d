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

int	check_map_content(char *line, t_tmp *tmp)
{
	size_t	index;
	char	*content;
	int		j;
	int		is_content;

	index = -1;
	content = " 10NSWE";
	while (line[++index] != '\0')
	{
		j = -1;
		is_content = FAIL;
		while (++j < 7)
		{
			if (line[index] == content[j])
			{
				if (content[j] == 'N' || content[j] == 'S' \
				|| content[j] == 'W' || content[j] == 'E')
					++tmp->user_count;
				is_content = SUCCESS;
			}
		}
		if (is_content == FAIL || tmp->user_count > 1)
			return (FAIL);
	}
	return (SUCCESS);
}

int	check_map_content2(char *line, t_tmp *tmp)
{
	size_t	index;
	char	*content;
	int		j;
	int		is_content;

	index = -1;
	content = " 10NSWE";
	while (line[++index] != '\0')
	{
		j = -1;
		is_content = FAIL;
		while (++j < 7)
		{
			if (line[index] == content[j])
			{
				is_content = SUCCESS;
			}
		}
		if (is_content == FAIL || tmp->user_count != 1)
			return (FAIL);
	}
	return (SUCCESS);
}
