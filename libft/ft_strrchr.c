/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:23:18 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:04:36 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strrchr(char *str, int n)
{
	int		index;
	char	*s_tmp;

	s_tmp = str;
	index = ft_strlen(str);
	while (*s_tmp)
		s_tmp++;
	while (index >= 0)
	{
		if (*s_tmp == (char)n)
			return (s_tmp);
		s_tmp--;
		index--;
	}
	return (0);
}
