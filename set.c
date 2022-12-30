#include "./header/cub3d.h"
#include <stdio.h>
#include <string.h>

void    set_map(t_game *game, t_tmp *tmp)
{
    t_node *node;

    node = tmp->tail->prev;
    game->map = (char *)malloc(sizeof(char) * (tmp->row * tmp->max_col + 1));
    game->row = tmp->row;
    game->col = tmp->max_col;
    while (node != tmp->head)
    {
        game->map = ft_strjoin(game->map, node->line);
        node = node->prev;
    }
}

void set_textures(t_game *game, char *tmp_line) {
    int width;
    int height;
    char **tmp;
    int index;

// 나중에 따로 함수로 뺄 것 + 하단 예외처리 각각
    tmp = ft_split(tmp_line, ' ');
    if (!ft_strncmp(tmp[0], "NO", 2))
        game->image[NO].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
            tmp[1], &width, &height);
    else if (!ft_strncmp(tmp[0], "WE", 2))
        game->image[WE].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
            tmp[1], &width, &height);
    else if (!ft_strncmp(tmp[0], "EA", 2))
        game->image[EA].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
            tmp[1], &width, &height);
    else if (!ft_strncmp(tmp[0], "SO", 2))
        game->image[SO].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, \
            tmp[1], &width, &height);
    else
        exit_with_error("Error\nNot Proper Direction\n");
    index = 0;

    // while (++index < 5)
    //     if (!game->image[index].img_ptr)
    //         exit_with_error("Error\nXpm File Does Not Exist\n");
    free_str(tmp, 2);
}

void    set_color(int *dir, char **color_arr)
{
    int color;

    color = 0;
    if (check_color(color_arr))
        exit_with_error("Error\nRGB Error\n");
    while (*color_arr != NULL) {
        *dir <<= 8;
        color = ft_atoi(*color_arr);
        *dir |= color;
        color_arr++;
    }
}

void set_floor_ceiling(t_game *game, char *tmp_line)
{
    char **div_dir;
    char **color_arr;

    div_dir = ft_split(tmp_line, ' ');
    color_arr = ft_split(div_dir[1], ',');
    if (!ft_strncmp(div_dir[0], "F", 1))
        set_color(&game->floor, color_arr);
    else if (!ft_strncmp(div_dir[0], "C", 1))
        set_color(&game->ceil, color_arr);
    else
        exit_with_error("Error\nWrong Argument");
}

/* 진짜 25줄 놈 때문에 이따구로 짰는데 더 좋은 방법이 있을지도...? */
void set_vec(t_vec *vec, char dir)
{
    if (dir == 'N' || dir == 'S')
    {
        vec->d_x = 0;
        vec->w_y = 0;
        vec->d_y = -1;
        vec->w_x = 0.66;
        if (dir == 'S')
        {
            vec->d_y = 1;
            vec->w_x = -0.66;
        }
    }
    else if (dir == 'W' || dir == 'E')
    {
        vec->d_y = 0;
        vec->w_x = 0;
        vec->d_x = 1;
        vec->w_y = 0.66;
        if (dir == 'W')
        {
            vec->d_x = -1;
            vec->w_y = -0.66;
        }
    }
}