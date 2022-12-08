/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:36:40 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:02:45 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_node	*ft_lstnew(char *tmp_line, int col)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == 0)
		return (NULL);
	node->line = ft_strdup(tmp_line);
	node->col = col;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
