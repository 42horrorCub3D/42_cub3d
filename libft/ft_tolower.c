/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:23:40 by minslee           #+#    #+#             */
/*   Updated: 2022/11/28 16:04:44 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_tolower(int n)
{
	int	nb;

	if (n >= 'A' && n <= 'Z')
		nb = n + 'a' - 'A';
	else
		nb = n;
	return (nb);
}
