/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:36:47 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:02:53 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tmp;
	size_t	index;

	tmp = (char *)s;
	index = 0;
	while (index < n)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
		index++;
	}
	return (0);
}
