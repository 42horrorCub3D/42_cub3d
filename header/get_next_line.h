/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:37:34 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 20:40:24 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_MAX (10526)
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "struct.h"

char	*get_next_line(int fd);

#endif
