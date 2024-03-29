/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:55:47 by minslee           #+#    #+#             */
/*   Updated: 2023/01/04 14:56:38 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	is_texture(char *line, int *result)
{
	char	*texture;
	int		texture_length;
	int		i;

	texture_length = 4;
	texture = "NSWE";
	i = 0;
	while (i < texture_length)
	{
		if (ft_strncmp(line, &texture[i], 1) == 0 && \
		check_flag_overlap(result, i) == FAIL)
		{
			set_bit_flag(i, result);
			return (SUCCESS);
		}
		i++;
	}
	return (FAIL);
}

int	is_background(char *line, int *result)
{
	char	*background;
	int		background_len;
	int		i;
	int		temp;
	int		texture_size;

	background_len = 2;
	background = "CF";
	texture_size = 4;
	i = 0;
	while (i < background_len)
	{
		if (ft_strncmp(line, &background[i], 1) == 0)
		{
			temp = *result >> texture_size;
			if (check_flag_overlap(&temp, i + texture_size) == FAIL)
			{
				set_bit_flag(i + texture_size, result);
				return (SUCCESS);
			}
		}
		i++;
	}
	return (FAIL);
}

int	check_flag_overlap(int *result, int index)
{
	int	copy;
	int	temp;

	copy = *result >> index;
	temp = 1;
	temp &= copy;
	if (temp == 0)
		return (FAIL);
	return (SUCCESS);
}

int	check_flag(int *result, int length)
{
	int	copy;
	int	temp;
	int	i;

	copy = *result;
	temp = 1;
	i = 0;
	while (i < length)
	{
		temp &= copy;
		if (temp == 0)
			return (FAIL);
		i++;
		copy >>= 1;
	}
	return (SUCCESS);
}

void	find_first_last(t_node **first, t_node **last)
{
	t_node	*f;
	t_node	*l;

	f = *first;
	l = *last;
	while (f->line[0] == '\0')
		f = f->next;
	while (l->line[0] == '\0')
		l = l->prev;
}
