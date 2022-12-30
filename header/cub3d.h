#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "struct.h"
# include "get_next_line.h"

/* check_imgae.c */
int check_is_all_digit(char *str);
int check_color(char **str);

/* check_map.c */
int check_top_bottom(char *line);
int check_side(char *line);
int check_middle(t_node *node);
int check_map(t_tmp *tmp);

/* error.c */
void    exit_with_error(const char *msg);

/* init.c */
void    init_side(t_ray *ray, t_vec *vec);
void    init_ray(t_ray *ray, int x, t_vec *vec);
void init_vec(t_tmp *tmp, t_vec *vec);
void init_tmp(t_tmp *tmp);
void init_game(t_game *game, int fd);

/* make_view.c */
int    make_view(t_game *game);
void    draw_ceil_floor(t_game *game);

/* move.c */
void move_camera(t_vec *vec, int sign);
void move_player_ad(t_game *game, int sign);
void move_player_sw(t_game *game, int sign);
int	key_press(int keycode, t_game *game);

/* parse_map.c */
void fill_map(t_tmp *tmp);
int     open_map(const char *file);
void    get_map(t_tmp *tmp, t_game *game, int fd);

/* ray_casting.c */
void dda(t_ray *ray, t_game *game, int x);
double get_wall_size(t_ray *ray, t_vec *vec);
int     get_color_from_texture(t_game *g, t_ray *ray, int pos);
void	calc_texture(t_ray *ray, t_game *game, t_wall *wall);
void	draw_texture(t_game *game, t_ray *ray, t_wall *wall, int x);

/* set_utils.c */
void	set_textures_util(t_game *game, char **tmp, int dir);

/* set.c */
void set_map(t_game *game, t_tmp *tmp);
void set_textures(t_game *game, char *tmp_line);
void    set_color(int *dir, char **color_arr);
void    set_floor_ceiling(t_game *game, char *tmp_line);
void    set_vec(t_vec *vec, char dir);
# endif