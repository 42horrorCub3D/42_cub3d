/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:37:00 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:03:21 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		str[11];
	long long	nb;
	int			index;

	index = 0;
	nb = (long long)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	else if (nb == 0)
		write(fd, "0", 1);
	while (nb > 0)
	{
		str[index++] = nb % 10 + '0';
		nb /= 10;
	}
	while (--index >= 0)
		write(fd, &str[index], 1);
}
