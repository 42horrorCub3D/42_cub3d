/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:47:21 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:03:02 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d_tmp;
	const char	*s_tmp;
	size_t		index;

	index = -1;
	d_tmp = dst;
	s_tmp = src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst < src)
		while (++index < len)
			d_tmp[index] = s_tmp[index];
	else
	{
		index = len;
		while (index > 0)
		{
			d_tmp[index - 1] = s_tmp[index - 1];
			index--;
		}
	}
	return (d_tmp);
}
