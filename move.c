/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minslee <minslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:36:51 by minslee           #+#    #+#             */
/*   Updated: 2022/12/30 20:36:51 by minslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/cub3d.h"

void	move_camera(t_vec *vec, int sign)
{
	double	d_x;
	double	w_x;
	double	degree;

	d_x = vec->d_x;
	w_x = vec->w_x;
	degree = (double)DEGREE / 5 * sign;
	vec->d_x = d_x * cos(degree) - vec->d_y * sin(degree);
	vec->d_y = d_x * sin(degree) + vec->d_y * cos(degree);
	vec->w_x = w_x * cos(degree) - vec->w_y * sin(degree);
	vec->w_y = w_x * sin(degree) + vec->w_y * cos(degree);
}

void	move_player_ad(t_game *game, int sign)
{
	double	goal_x;
	double	goal_y;
	char	content_x;
	char	content_y;

	goal_x = game->vec->p_x + game->vec->w_x * WALK_SPEED / 5 * sign;
	goal_y = game->vec->p_y + game->vec->w_y * WALK_SPEED / 5 * sign;
	content_x = game->map[(int)game->vec->p_y * game->col + (int)goal_x];
	content_y = game->map[(int)goal_y * game->col + (int)game->vec->p_x];
	if (content_x != '1')
		game->vec->p_x = goal_x;
	if (content_y != '1')
		game->vec->p_y = goal_y;
}

void	move_player_sw(t_game *game, int sign)
{
	double	goal_x;
	double	goal_y;
	char	content_x;
	char	content_y;

	goal_x = game->vec->p_x + game->vec->d_x * WALK_SPEED / 5 * sign;
	goal_y = game->vec->p_y + game->vec->d_y * WALK_SPEED / 5 * sign;
	content_x = game->map[(int)game->vec->p_y * game->col + (int)goal_x];
	content_y = game->map[(int)goal_y * game->col + (int)game->vec->p_x];
	if (content_x != '1')
		game->vec->p_x = goal_x;
	if (content_y != '1')
		game->vec->p_y = goal_y;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_with_error("FINISHED\n");
	else if (keycode == KEY_A)
		move_player_ad(game, -1);
	else if (keycode == KEY_D)
		move_player_ad(game, 1);
	else if (keycode == KEY_S)
		move_player_sw(game, -1);
	else if (keycode == KEY_W)
		move_player_sw(game, 1);
	else if (keycode == KEY_R)
		move_camera(game->vec, 1);
	else if (keycode == KEY_L)
		move_camera(game->vec, -1);
	return (0);
}
