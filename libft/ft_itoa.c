/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:36:02 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:02:36 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	get_num_size(int n)
{
	int			size;
	long long	nb;

	size = 0;
	nb = (long long)n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long	nb;
	char		*str;
	int			len;

	str = (char *)malloc(sizeof(char) * (get_num_size(n) + 1));
	if (str == 0)
		return (0);
	nb = (long long)n;
	len = get_num_size(n);
	if (n < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	else if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
