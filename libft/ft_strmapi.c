/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:37:22 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:04:25 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*str;

	index = 0;
	if (s == 0 || f == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == 0)
		return (0);
	while (index < (unsigned int)ft_strlen(s))
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = 0;
	return (str);
}	
