#include "./header/cub3d.h"
#include <stdio.h>

void dda(t_ray *ray, t_game *game, int x)
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

    //printf("[%d]\n", ray->map_x);

      if(ray->side == 0)
      {
        ray->wall_d = (ray->side_x - ray->delta_x);
      }   
      else
      {
        ray->wall_d = (ray->side_y - ray->delta_y);
      }

      int lineHeight = (int)(HEIGHT / ray->wall_d);
      //printf("%d %f %d \n", lineHeight, ray->wall_d, HEIGHT);
      int drawStart = -lineHeight / 2 + HEIGHT / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + HEIGHT / 2;
      if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

      int color = 0xFFFFFF;

      //verLine(x, drawStart, drawEnd, color);
      for (int y = drawStart; y < drawEnd; y++)
        mlx_pixel_put(game->mlx_ptr, game->mlx_win, x, y, color);
}

// double get_wall_size(t_ray *ray, t_vec *vec)
// {
//     if (ray->side == 0)
//     {
//         ray->wall_d = (ray->map_x - vec->p_x + (1 - ray->step_x) / 2) / ray->ray_x;
//         if (ray->wall_d <= 0.000001)
//             ray->wall_d = 0.000001;
//         return (vec->p_y + ray->ray_y * ray->wall_d);
//     }
//     ray->wall_d = (ray->map_y - vec->p_y + (1 - ray->step_y) / 2) / ray->ray_y;
//     if (ray->wall_d <= 0.000001)
//         ray->wall_d = 0.000001;
//     return (vec->p_x + ray->ray_x * ray->wall_d);
// }