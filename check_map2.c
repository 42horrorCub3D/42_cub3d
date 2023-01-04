#include "header/cub3d.h"

int	is_texture(char *line, int *result)
{
	char	*texture;
	int		texture_length;
	int		i;

	texture_length = 4;
	texture = "NSWE";
	i = 0;
	while (i < texture_length)
	{
		if (ft_strncmp(line, &texture[i], 1) == 0 && \
		check_flag_overlap(result, i) == FAIL)
		{
			set_bit_flag(i, result);
			return (SUCCESS);
		}
		i++;
	}
	return (FAIL);
}

int	is_background(char *line, int *result)
{
	char	*background;
	int		background_len;
	int		i;
	int		temp;
	int		texture_size;

	background_len = 2;
	background = "CF";
	texture_size = 4;
	i = 0;
	while (i < background_len)
	{
		if (ft_strncmp(line, &background[i], 1) == 0)
		{
			temp = *result >> texture_size;
			if (check_flag_overlap(&temp, i + texture_size) == FAIL)
			{
				set_bit_flag(i + texture_size, result);
				return (SUCCESS);
			}
		}
		i++;
	}
	return (FAIL);
}

int	check_flag_overlap(int *result, int index)
{
	int	copy;
	int	temp;

	copy = *result >> index;
	temp = 1;
	temp &= copy;
	if (temp == 0)
		return (FAIL);
	return (SUCCESS);
}

int	check_flag(int *result, int length)
{
	int	copy;
	int	temp;
	int	i;

	copy = *result;
	temp = 1;
	i = 0;
	while (i < length)
	{
		temp &= copy;
		if (temp == 0)
			return (FAIL);
		i++;
		copy >>= 1;
	}
	return (SUCCESS);
}

void	set_bit_flag(int index, int *result)
{
	int	i;
	int	bit_pos;

	if (index == 0)
	{
		*result |= 1;
	}
	else
	{
		i = 0;
		bit_pos = 1;
		while (i < index)
		{
			bit_pos *= 2;
			i++;
		}
		*result |= bit_pos;
	}
}

void	set_next_line(int fd, char **out_line)
{
	free(*out_line);
	*out_line = get_next_line(fd);
}

int	check_map_content(char *line)
{
	size_t	index;
	char	*content;
	int		j;
	int		length;
	int		is_content;

	index = -1;
	content = " 10NSWE";
	is_content = FAIL;
	length = 7;
	while (line[++index] != '\0')
	{
		j = -1;
		while (++j < length)
		{
			if (line[index] == content[j])
			{
				is_content = SUCCESS;
				break ;
			}
		}
		if (is_content == FAIL)
			return (FAIL);
		is_content = FAIL;
	}
	return (SUCCESS);
}
