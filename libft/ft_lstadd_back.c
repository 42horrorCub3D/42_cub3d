/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:36:17 by minslee           #+#    #+#             */
/*   Updated: 2022/12/02 09:10:47 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_lstadd_back(t_tmp *tmp, char *tmp_line, int col)
{
	t_node	*t;
	t_node	*new;

	t = tmp->tail;
	new = ft_lstnew(tmp_line, col);
	t->prev->next = new;
	new->prev = t->prev;
	t->prev = new;
	new->next = t;
}
