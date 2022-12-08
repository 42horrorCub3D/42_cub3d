/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:48:29 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:53:09 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strdup(char *s1)
{
	char	*dest;
	size_t	index;

	index = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest == 0)
		return (0);
	else
	{
		while (index < ft_strlen(s1))
		{
			dest[index] = s1[index];
			index++;
		}
		dest[index] = 0;
	}
	return (dest);
}
