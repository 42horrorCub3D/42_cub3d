#include "./header/cub3d.h"
#include <stdio.h>
void	move_camera(t_vec *vec, int sign)
{
	vec->d_x = vec->d_x * cos(DEGREE) - (sign) * vec->d_y * sin(DEGREE);
	vec->d_y = (sign) * vec->d_x * sin(DEGREE) + vec->d_y + cos(DEGREE);
	vec->w_x = vec->w_x * cos(DEGREE) - (sign) * vec->w_y * sin(DEGREE);
	vec->w_y = (sign) * vec->w_x * sin(DEGREE) + vec->w_y + cos(DEGREE);
}

void move_player_ad(t_game *game, int sign)
{
	double	goal_x;
	double	goal_y;
	char	contentX;
	char	contentY;

	goal_x = game->vec->p_x + game->vec->w_x * WALK_SPEED * sign;
	goal_y = game->vec->p_y + game->vec->w_y * WALK_SPEED * sign;
	contentX = game->map[(int)game->vec->p_y * game->col + (int)goal_x];
	contentY = game->map[(int)goal_y * game->col + (int)game->vec->p_x];
	if (contentX != '1')
		game->vec->p_x = goal_x;
	if (contentY != '1')
		game->vec->p_y = goal_y;
	make_view(game);
}

void move_player_sw(t_game *game, int sign)
{
	double	goal_x;
	double	goal_y;
	char	contentX;
	char	contentY;

	goal_x = game->vec->p_x + game->vec->d_x * WALK_SPEED * sign;
	goal_y = game->vec->p_y + game->vec->d_y * WALK_SPEED * sign;
	contentX = game->map[(int)game->vec->p_y * game->col + (int)goal_x];
	contentY = game->map[(int)goal_y * game->col + (int)game->vec->p_x];
	if (contentX != '1')
		game->vec->p_x = goal_x;
	if (contentY != '1')
		game->vec->p_y = goal_y;
	make_view(game);
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
		move_camera(game->vec, -1);
	else if (keycode == KEY_L)
		move_camera(game->vec, 1);
	return (0);
}