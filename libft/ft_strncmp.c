/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:22:00 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:04:31 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			index;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	index = 0;
	if (n == 0)
		return (0);
	while (index < n)
	{
		if (s1[index] == 0 && s2[index] == 0)
			return (0);
		else if (s1[index] == 0)
			return (-1);
		else if (s2[index] == 0)
			return (1);
		else if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	index--;
	return (s1[index] - s2[index]);
}
