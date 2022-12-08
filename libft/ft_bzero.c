/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:41:51 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:02:05 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_bzero(void *dest, size_t size)
{
	size_t	index;
	char	*tmp;

	tmp = (char *)dest;
	index = 0;
	while (index < size)
		tmp[index++] = 0;
}
