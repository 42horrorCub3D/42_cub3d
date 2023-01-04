/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:37:39 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 20:59:59 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "struct.h"
# include "get_next_line.h"

/* check_imgae.c */
int		check_is_all_digit(char *str);
int		check_color(char **str);

/* check_map.c */
int		check_top_bottom(char *line);
int		check_side(char *line);
int		check_middle(t_node *node);
int		check_map(t_tmp *tmp);
int		check_nl(t_node *node, t_tmp *tmp);

/* check_map2.c */
int		is_texture(char *line, int *result);
int		is_background(char *line, int *result);
int		check_flag_overlap(int *result, int index);
int		check_flag(int *result, int length);
void	set_bit_flag(int index, int *result);

/* check_map3.c */
int		check_2d_array(char **str, int count);
int		check_map_content(char *line, t_tmp *tmp);
int     check_map_content2(char *line, t_tmp *tmp);
void	set_next_line(int fd, char **out_line);

/* error.c */
void	exit_with_error(const char *msg);

/* ft_free.c */
void	free_tmp(t_tmp *tmp);
int		get_length_spilited(char **arr);
void	check_mlx_ptr_load(void **mlx_ptrs);

/* init.c */
void	init_side(t_ray *ray, t_vec *vec);
void	init_ray(t_ray *ray, int x, t_vec *vec);
void	init_vec(t_tmp *tmp, t_vec *vec);
void	init_tmp(t_tmp *tmp);
void	init_game(t_game *game, int fd);

/* make_view.c */
int		make_view(t_game *game);
void	draw_ceil_floor(t_game *game);

/* move.c */
void	move_camera(t_vec *vec, int sign);
void	move_player_ad(t_game *game, int sign);
void	move_player_sw(t_game *game, int sign);
int		key_press(int keycode, t_game *game);

/* parse_map.c */
void	set_tmp(t_tmp *tmp, char *tmp_line, int *row);
void	fill_map(t_tmp *tmp);
void	get_max_col(t_tmp *tmp);
void	get_map(t_tmp *tmp, t_game *game, int fd);
int		open_map(const char *file);

/* ray_casting.c */
void	dda(t_ray *ray, t_game *game, int x, t_wall *wall);
int		get_color_from_texture(t_game *g, t_ray *ray, int pos);
double	get_wall_size(t_ray *ray, t_vec *vec);
void	calc_texture(t_ray *ray, t_game *game, t_wall *wall);
void	draw_texture(t_game *game, t_ray *ray, t_wall *wall, int x);

/* set_utils.c */
void	set_textures_util(t_game *game, char **tmp, int dir);

/* set.c */
void	set_map(t_game *game, t_tmp *tmp);
void	set_textures(t_game *game, char *tmp_line);
void	set_color(int *dir, char **color_arr);
void	set_floor_ceiling(t_game *game, char *tmp_line);
void	set_vec(t_vec *vec, char dir);

#endif
