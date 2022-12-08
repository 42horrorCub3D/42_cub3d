#include "./header/cub3d.h"

void dda(t_ray *ray, t_game *game)
{
    while (ray->hit == 0)
    {
        if (ray->side_x < ray->side_y)
        {
            ray->side_x += ray->delta_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_y += ray->delta_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (game->map[ray->map_y * game->col + ray->map_x] == '1')
            ray->hit = 1;
    }
}

double get_wall_size(t_ray *ray, t_vec *vec)
{
    if (ray->side == 0)
    {
        ray->wall_d = (ray->map_x - vec->p_x + (1 - ray->step_x) / 2) / ray->ray_x;
        if (ray->wall_d <= 0.000001)
            ray->wall_d = 0.000001;
        return (vec->p_y + ray->ray_y * ray->wall_d);
    }
    ray->wall_d = (ray->map_y - vec->p_y + (1 - ray->step_y) / 2) / ray->ray_y;
    if (ray->wall_d <= 0.000001)
        ray->wall_d = 0.000001;
    return (vec->p_x + ray->ray_x * ray->wall_d);
}