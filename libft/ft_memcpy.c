/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:47:16 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:03:05 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d_tmp;
	char	*s_tmp;
	size_t	index;

	if (dest == 0 && src == 0)
		return (0);
	d_tmp = (char *)dest;
	s_tmp = (char *)src;
	index = 0;
	while (index < n)
	{
		d_tmp[index] = s_tmp[index];
		index++;
	}
	return (d_tmp);
}
