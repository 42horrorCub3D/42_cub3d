/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:47:59 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:03:08 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;
	size_t	index;

	p = (char *)b;
	index = 0;
	while (index < len)
	{
		p[index] = (char)c;
		index++;
	}
	return (p);
}
