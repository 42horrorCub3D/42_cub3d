/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:18:50 by minslee           #+#    #+#             */
/*   Updated: 2022/12/02 09:21:04 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ch;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	ch = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ch)
		return (0);
	ft_memcpy(ch, s1, ft_strlen(s1));
	ft_memcpy(&ch[ft_strlen(s1)], s2, ft_strlen(s2));
	ch[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	s1 = NULL;
	return (ch);
}
