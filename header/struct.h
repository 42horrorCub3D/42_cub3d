/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:37:22 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 20:42:04 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define _USE_MATH_DEFINES
# include "math.h"
# include "../mlx/mlx.h"

# define BUFFER_SIZE    (100)
# define COMPONENT_SIZE (6)
# define FAIL       (0)
# define SUCCESS    (1)
# define X_EVENT_KEY_RELEASE	(2)
# define X_EVENT_KEY_EXIT		(17)
# define KEY_ESC		    	(53)
# define KEY_W			    	(13)
# define KEY_A			    	(0)
# define KEY_S              	(1)
# define KEY_D			    	(2)
# define KEY_R                  (124)
# define KEY_L                  (123)
# define WIDTH                  (680)
# define HEIGHT                 (480)
# define WALK_SPEED             (2)
# define DEGREE                 (M_PI)
# define TEX_WIDTH				(64)
# define TEX_HEIGHT				(64)

enum e_DIR {
	BUF = 0,
	NO = 1,
	WE = 2,
	EA = 3,
	SO = 4,
	DIR_CNT = 5,
};

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			*line;
	int				col;
}	t_node;

typedef struct s_tmp
{
	t_node	*head;
	t_node	*tail;
	int		max_col;
	int		row;
	int		flag;
	int		user_count;
	int		is_component;
}	t_tmp;

typedef struct s_vec
{
	double	p_x;
	double	p_y;
	double	d_x;
	double	d_y;
	double	w_x;
	double	w_y;
}	t_vec;

typedef struct s_ray
{
	double	cam;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	wall_d;
}	t_ray;

typedef struct s_image
{
	void	*img_ptr;
	int		*img_data;
	int		bits;
	int		line_size;
	int		endien;
}	t_image;

typedef struct s_wall
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		tex_x;
	int		line_h;
	int		start;
	int		end;	
}	t_wall;

typedef struct s_game
{
	char		*map;
	int			row;
	int			col;
	t_vec		*vec;
	void		*mlx_ptr;
	void		*mlx_win;
	t_image		image[DIR_CNT];
	int			floor;
	int			ceil;
	void		*win;
}	t_game;

#endif
