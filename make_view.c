#include "./header/cub3d.h"

int    make_view(t_game *game) {
    int x;
    t_ray ray;

    x = -1;
    while (++x < WIDTH)
    {
        init_ray(&ray, x, game->vec);
        init_side(&ray, game->vec);
        dda(&ray, game);
    }
    return (0);
}