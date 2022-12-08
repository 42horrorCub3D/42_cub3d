/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:42:38 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:02:12 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	index;

	p = (char *)malloc(count * size);
	if (p == 0)
		return (0);
	index = 0;
	while (index < count * size)
		p[index++] = 0;
	return (p);
}
