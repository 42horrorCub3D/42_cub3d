#ifndef STRUCT_H
# define STRUCT_H

# include "../mlx/mlx.h"

# define BUFFER_SIZE    (100)
# define FAIL       (1)
# define SUCCESS    (0)
# define X_EVENT_KEY_PRESS  	(2)
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
# define WALK_SPEED             (1)
# define DEGREE                 (1)
# define TEXTURE                (64)

typedef struct s_node
{
    struct s_node  *next;
    struct s_node  *prev;
    char    *line;
    int     col;
}   t_node;

typedef struct s_tmp
{
    t_node  *head;
    t_node  *tail;
    int     max_col;
    int     row;
}	t_tmp;

typedef struct s_vec
{
    double  p_x; /* player x, y */
    double  p_y;
    double  d_x; /* direction x, y */
    double  d_y;
    double  w_x; /* plane(window) x, y */
    double  w_y;
} t_vec;

typedef struct s_ray
{
    double cam; /* cam horizontal */
    double ray_x; /* 광선의 방향벡터 */
    double ray_y;
    int map_x;
    int map_y;
    double side_x;
    double side_y;
    double delta_x;
    double delta_y;
    int step_x;
    int step_y;
    int hit;
    int side;
    double wall_d;
} t_ray;

typedef struct s_image
{
    void    *ea;
    void    *so;
    void    *we;
    void    *no;
    int     ceil;
    int     floor;
    int     **bg;
} t_image;

typedef struct s_game
{
    char        *map;
    int         row;
    int         col;
    t_vec       *vec;
    void        *mlx_ptr;
    void        *mlx_win;
    t_image     *image;
    void		*win;
} t_game;

#endif