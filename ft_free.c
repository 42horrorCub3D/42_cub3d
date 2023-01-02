/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:26:24 by jokang            #+#    #+#             */
/*   Updated: 2022/12/31 20:26:27 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	free_tmp(t_tmp *tmp)
{
	t_node	*iter;
	t_node	*cache;

	iter = tmp->head;
	while (iter != tmp->tail)
	{
		cache = iter->next;
		free(iter->line);
		free(iter);
		iter = cache;
	}
	free(iter->line);
	free(iter);
	free(tmp);
}

int	get_length_spilited(char **arr)
{
	char	**temp;
	int		length;

	temp = arr;
	length = 0;
	while (*temp != NULL)
	{
		temp++;
		length++;
	}

	return (length);
}

void	check_mlx_ptr_load(void **mlx_ptrs)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (mlx_ptrs[i] == NULL)
			exit_with_error("Error\nFail to use MLX library!\n");
	}
}
