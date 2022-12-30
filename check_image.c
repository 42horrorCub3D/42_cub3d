#include "./header/cub3d.h"

int	check_is_all_digit(char *str)
{
	int	index;

	index = -1;
	while (str[++index] != '\0')
		if (!ft_isdigit(str[index]))
			return (0);
	return (1);
}

int	check_color(char **str)
{
	int	row;

	row = 0;
	while (str[row] != NULL)
		row++;
	if (row != 3)
		return (1);
	row = 0;
	while (str[row] != NULL)
	{
		if (!check_is_all_digit(str[row]))
			return (1);
		if (ft_atoi(str[row]) < 0 || ft_atoi(str[row]) > 255)
			return (1);
		row++;
	}
	return (0);
}
