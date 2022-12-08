/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:19:25 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:04:16 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	d_size;
	size_t	s_size;
	size_t	index;

	d_size = ft_strlen(dest);
	s_size = ft_strlen(src);
	if (!dest || !src || len == 0)
		return (s_size);
	index = 0;
	while (src[index] && d_size + index < len - 1)
	{
		dest[d_size + index] = src[index];
		index++;
	}
	if (d_size > len)
		return (s_size + len);
	else
	{
		dest[d_size + index] = 0;
		return (d_size + s_size);
	}
}
