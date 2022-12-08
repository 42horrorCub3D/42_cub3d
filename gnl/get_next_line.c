/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:37:25 by minslee           #+#    #+#             */
/*   Updated: 2022/12/02 10:04:22 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

int	check_new_line(char *r_line)
{
	int	i;

	i = 0;
	while (r_line[i])
	{
		if (r_line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*print_line(int new_line, char **r_line)
{
	char	*p_line;
	char	*tmp;

	tmp = NULL;
	if ((new_line != -1) && ((new_line + 1) != (int)ft_strlen(*r_line)))
	{
		tmp = ft_strdup(*r_line + new_line + 1);
		if (!tmp)
		{
			free(*r_line);
			*r_line = 0;
			return (NULL);
		}
	}
	(*r_line)[new_line + 1] = '\0';
	p_line = ft_strdup(*r_line);
	if (!p_line)
	{
		free(*r_line);
		*r_line = 0;
		return (NULL);
	}
	free(*r_line);
	*r_line = tmp;
	return (p_line);
}

char	*free_line(char **r_line)
{
	int		new_line;
	char	*p_line;

	new_line = 0;
	p_line = 0;
	if (!(*r_line))
	{
		return (NULL);
	}
	new_line = check_new_line(*r_line);
	if (new_line >= 0)
		return (print_line(new_line, &(*r_line)));
	p_line = ft_strdup(*r_line);
	if (p_line == 0)
	{
		free(*r_line);
		*r_line = 0;
		return (0);
	}
	free(*r_line);
	*r_line = 0;
	return (p_line);
}

char	*get_next_two(int size, char *str, char **r_line, int fd)
{
	int	new_line;

	new_line = 0;
	while (size > 0)
	{
		str[size] = '\0';
		*r_line = ft_strjoin(*r_line, str);
		new_line = check_new_line(*r_line);
		if (new_line >= 0)
		{
			free(str);
			str = NULL;
			return (print_line(new_line, &(*r_line)));
		}
		size = read(fd, str, BUFFER_SIZE);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*r_line[OPEN_MAX];
	int			size;
	char		*str;
	char		*re;

	if ((fd < 0) || (fd > OPEN_MAX) || (BUFFER_SIZE <= 0))
		return (NULL);
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (0);
	size = read(fd, str, BUFFER_SIZE);
	if (size > 0)
	{
		re = get_next_two(size, str, &r_line[fd], fd);
		if (re != 0)
			return (re);
	}
	free(str);
	str = NULL;
	if (size < 0)
		return (NULL);
	return (free_line(&r_line[fd]));
}
