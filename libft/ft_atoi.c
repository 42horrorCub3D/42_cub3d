/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:37:55 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:00:48 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\r')
		return (1);
	else if (c == '\v' || c == '\f' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			neg;
	long long	tmp;

	neg = 1;
	num = 0;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	while (*str >= '0' && *str <= '9')
	{
		tmp = num;
		num = num * 10 + *str++ - '0';
		if ((neg * num) < tmp && neg == 1)
			return (-1);
		if ((neg * num) > tmp && neg == -1)
			return (0);
	}
	return ((int)(num * neg));
}
