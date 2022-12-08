/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:37:15 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:04:12 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (s != 0 && f != 0)
	{
		index = 0;
		while (index < (unsigned int)ft_strlen(s))
		{
			f(index, &s[index]);
			index++;
		}
	}
}
