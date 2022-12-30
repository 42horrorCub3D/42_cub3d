#include "./header/cub3d.h"

void	dda(t_ray *ray, t_game *game, int x)
{
	t_wall wall;

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
	calc_texture(ray, game, &wall);
	draw_texture(game, ray, &wall, x);

}

int	get_color_from_texture(t_game *g, t_ray *ray, int pos)
{
	int	pixel_color;

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
	return (pixel_color);
}

double get_wall_size(t_ray *ray, t_vec *vec)
{
	double wall_size;

	if (ray->side == 0 || ray->side == 1)
	{
		ray->wall_d = (ray->map_x - vec->p_x + (1 - ray->step_x) / 2) / ray->ray_x;
		if (ray->wall_d <= 0.000001)
			ray->wall_d = 0.00001;
		return (vec->p_y + ray->ray_y * ray->wall_d);
	}
	ray->wall_d = (ray->map_y - vec->p_y + (1 - ray->step_y) / 2) / ray->ray_y;
	if (ray->wall_d <= 0.000001)
		ray->wall_d = 0.00001;
	return (vec->p_x + ray->ray_x * ray->wall_d);
}

void	calc_texture(t_ray *ray, t_game *game, t_wall *wall)
{
	wall->wall_x = get_wall_size(ray, game->vec);
	wall->wall_x -= floor(wall->wall_x);
	wall->tex_x = (int)(wall->wall_x * (double)TEX_WIDTH);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_x > 0)
		wall->tex_x = TEX_WIDTH - wall->tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->ray_y < 0)
		wall->tex_x = TEX_WIDTH - wall->tex_x - 1;
	wall->line_h = (int)(HEIGHT / ray->wall_d);
	wall->start = -wall->line_h / 2 + HEIGHT / 2;
	if (wall->start < 0)
		wall->start = 0;
	wall->end = wall->line_h / 2 + HEIGHT / 2;
	if (wall->end >= HEIGHT)
		wall->end = HEIGHT - 1;
}

void	draw_texture(t_game *game, t_ray *ray, t_wall *wall, int x)
{
	int	y;
	int color_pos;

	y = wall->start;
	wall->step = 1.0 * TEX_HEIGHT / wall->line_h;
	wall->tex_pos = (wall->start - HEIGHT / 2 + wall->line_h / 2) * wall->step;
	while (y < wall->end)
	{
		wall->tex_y = (int)wall->tex_pos & (TEX_HEIGHT - 1);
		wall->tex_pos += wall->step;
		color_pos = TEX_HEIGHT * wall->tex_y + wall->tex_x;
		game->image[BUF].img_data[x + WIDTH * y] = get_color_from_texture(game, ray, color_pos);
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->image[BUF].img_ptr, 0, 0);
}