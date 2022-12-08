/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:23:36 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:47:49 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	size;

	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		size = ft_strlen(s) - start + 1;
	else
		size = len + 1;
	dest = (char *)malloc(sizeof(char) * (size));
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}
