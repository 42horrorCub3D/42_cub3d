/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:38:32 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:49:22 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	is_in_str(char c, char const *s2)
{
	int	index;

	index = 0;
	while (s2[index])
	{
		if (s2[index] == c)
			return (1);
		index++;
	}
	return (0);
}

static int	set_start_end(char const *s1, char const *s2, int *end, int *start)
{
	while (*start < (int)ft_strlen(s1) / 2)
	{
		if (!is_in_str(s1[*start], s2))
			break ;
		*start += 1;
	}
	while (*end >= (int)ft_strlen(s1) / 2)
	{
		if (!is_in_str(s1[*end], s2))
			break ;
		*end -= 1;
	}
	return (*end - *start + 1);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	str = 0;
	if (s1 != 0 && s2 != 0)
	{
		start = 0;
		end = ft_strlen(s1) - 1;
		len = set_start_end(s1, s2, &end, &start);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str == 0)
			return (0);
		len = 0;
		while (start <= end)
			str[len++] = s1[start++];
		str[len] = 0;
	}
	return (str);
}
