#include "./header/cub3d.h"

void	set_textures_util(t_game *game, char **tmp, int dir)
{
	int	width;
	int	height;

	game->image[dir].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
		tmp[1], &width, &height);
	if (!game->image[dir].img_ptr)
		exit_with_error("Error\nXpm File Does Not Exist\n");
}
