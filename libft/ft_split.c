/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:37:06 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:53:00 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	get_size(char const *s, char c)
{
	size_t	size;
	size_t	index;

	index = 0;
	size = 0;
	while (s[index] != 0)
	{
		if (s[index] == c && index > 0)
		{
			if (index < ft_strlen(s) - 1 && s[index + 1] != c)
				size++;
		}
		else if (index == ft_strlen(s) - 1 && s[index] != c)
			size++;
		index++;
	}
	return (size);
}

void	free_str(char **str, int row)
{
	int	index;

	index = 0;
	while (index < row)
	{
		free(str[index++]);
	}
	free(str);
}

static int	get_split(char const *s, char c, char **str, int row)
{
	int			len;
	int			index;

	index = 0;
	while (s[index] != c && s[index] != 0)
		index++;
	len = index;
	str[row] = (char *)malloc(sizeof(char) * (len + 1));
	if (str[row] == 0)
	{
		free_str(str, row);
		return (0);
	}
	index = 0;
	while (index < len)
	{
		str[row][index] = s[index];
		index++;
	}
	str[row][index] = 0;
	return (index);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		row;
	int		check;

	row = 0;
	if (!s)
		return (0);
	str = (char **)malloc(sizeof(char *) * (get_size(s, c) + 1));
	if (str == 0)
		return (0);
	while (*s != 0)
	{
		if (*s != c)
		{
			check = get_split(s, c, str, row);
			if (check == 0)
				return (0);
			row++;
			s += check;
		}
		else
			s++;
	}
	str[row] = 0;
	return (str);
}
