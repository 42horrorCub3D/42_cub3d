#include "./header/cub3d.h"
#include <stdio.h>

int    make_view(t_game *game) {
    int x;
    t_ray ray;

    x = -1;
    /* ceiling, floor draw */
    draw_ceil_floor(game);

    printf("%f %f\n", game->vec->p_x, game->vec->p_y);
    while (++x < WIDTH)
    {
        init_ray(&ray, x, game->vec);
        printf("%f %f %f\n", ray.cam, ray.ray_x, ray.ray_y);
        init_side(&ray, game->vec);
        if (ray.map_x < 0)
        {
            printf("%d\n", 31231);
        }
        dda(&ray, game, x);
    }
    return (0);
}

void    draw_ceil_floor(t_game *game) {
    int x;
    int y;

    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            if (y < HEIGHT / 2)
                mlx_pixel_put(game->mlx_ptr, game->mlx_win, x, y, game->image->floor);
            else
                mlx_pixel_put(game->mlx_ptr, game->mlx_win, x, y, game->image->ceil);
            y++;
        }
        x++;
    }
}