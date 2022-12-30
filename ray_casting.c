#include "./header/cub3d.h"
#include <stdio.h>

void dda(t_ray *ray, t_game *game, int x)
{
    double wall;
    int tex_x;

	while (ray->hit == 0)
	{
        if (ray->side_x < ray->side_y)
        {
            ray->side_x += ray->delta_x;
            ray->map_x += ray->step_x;
            if (ray->step_x == 1)
              ray->side = 0;
            else
              ray->side = 1;
        }
        else
        {
            ray->side_y += ray->delta_y;
            ray->map_y += ray->step_y;
            if (ray->step_y == 1)
              ray->side = 2;
            else
              ray->side = 3;
        }
        if (game->map[ray->map_y * game->col + ray->map_x] == '1')
            ray->hit = 1;
    }

      if(ray->side == 0 || ray->side == 1)
      {
        ray->wall_d = (ray->map_x - game->vec->p_x + (1 - ray->step_x) / 2) / ray->ray_x;
      }   
      else
      {
        ray->wall_d = (ray->map_y - game->vec->p_y + (1 - ray->step_y) / 2) / ray->ray_y;
      }

			int lineHeight = (int)(HEIGHT / ray->wall_d);

			int drawStart = -lineHeight / 2 + HEIGHT / 2;
			if(drawStart < 0)
			{
				drawStart = 0;
			}
			int drawEnd = lineHeight / 2 + HEIGHT / 2;

      if(drawEnd >= HEIGHT)
      {
        drawEnd = HEIGHT - 1;
      }


      // DRAWING TEXUTRE 1

      double wallX; //where exactly the wall was hit
      if (ray->side == 0) wallX = game->vec->p_y + ray->wall_d * ray->ray_y;
      else           wallX = game->vec->p_x + ray->wall_d * ray->ray_x;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = (int)(wallX * (double)TEX_WIDTH);
      if(ray->side == 0 && ray->ray_x > 0) texX = TEX_WIDTH - texX - 1;
      if(ray->side == 1 && ray->ray_y < 0) texX = TEX_WIDTH - texX - 1;

  

      // DRAWING TEXUTRE 2

      double step = 1.0 * TEX_HEIGHT / lineHeight;
      // Starting texture coordinate
      double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;
      for(int y = drawStart; y < drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (TEX_HEIGHT - 1);
        texPos += step;
        int color_pos = TEX_HEIGHT * texY + texX;
        game->image[BUF].img_data[x + WIDTH * y] = get_color_from_texture(game, ray, color_pos);
      }

      mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->image[BUF].img_ptr, 0, 0);
}

int get_color_from_texture(t_game *g, t_ray *ray, int pos)
{
  int pixel_color;

  pixel_color = 0xFFFFFF;
  if (ray->side == 3)
  {
    pixel_color = g->image[NO].img_data[pos];
  }
  else if (ray->side == 2)
  {
    pixel_color = g->image[SO].img_data[pos];
  }
  else if (ray->side == 1)
  {
    pixel_color = g->image[WE].img_data[pos];
  }
  else if (ray->side == 0)
  {
    pixel_color = g->image[EA].img_data[pos];
  }
  return pixel_color;
}

double get_wall_size(t_ray *ray, t_vec *vec)
{
    double wall_size;

	if (ray->side == 0)
	{
		ray->wall_d = (ray->map_x - vec->p_x + (1 - ray->step_x) / 2) / ray->ray_x;
		if (ray->wall_d <= 0.000001)
			ray->wall_d = 0.000001;
        /* 추가 */
        wall_size = vec->p_y + ray->ray_y * ray->wall_d;
        return (wall_size - floor(wall_size));
		//return (vec->p_y + ray->ray_y * ray->wall_d);
	}
	ray->wall_d = (ray->map_y - vec->p_y + (1 - ray->step_y) / 2) / ray->ray_y;
	if (ray->wall_d <= 0.000001)
		ray->wall_d = 0.000001;
    /* 추가 */
    wall_size = vec->p_x + ray->ray_x * ray->wall_d;
    return (wall_size - floor(wall_size));
	//return (vec->p_x + ray->ray_x * ray->wall_d);
}