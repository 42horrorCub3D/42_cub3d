#include "./header/cub3d.h"
#include <stdio.h>

int    make_view(t_game *game) {
    int x;
    t_ray ray;

    x = -1;
    /* ceiling, floor draw */
    draw_ceil_floor(game);

<<<<<<< HEAD
=======
    //printf("%f %f\n", game->vec->p_x, game->vec->p_y);
>>>>>>> e5fe036dc9f0bdccb1485c8174f4974db5e2af0a
    while (++x < WIDTH)
    {
        init_ray(&ray, x, game->vec);
        init_side(&ray, game->vec);
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