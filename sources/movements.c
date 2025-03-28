/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:59:20 by mmasoni           #+#    #+#             */
/*   Updated: 2024/04/04 10:19:19 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_player(t_game *game, int i)
{
	if (i == 1)
	{
		game->player->ang_dir += ROTATION_SPEED;
		if (game->player->ang_dir > 2 * M_PI)
			game->player->ang_dir -= 2 * M_PI;
	}
	else
	{
		game->player->ang_dir -= ROTATION_SPEED;
		if (game->player->ang_dir < 0)
			game->player->ang_dir += 2 * M_PI;
	}
}

void	move_player(t_game *game, double move_x, double move_y)
{
	int		map_grid_y;
	int		map_grid_x;
	int		new_x;
	int		new_y;

	new_x = roundf(game->player->pl_pix_x + move_x);
	new_y = roundf(game->player->pl_pix_y + move_y);
	map_grid_x = (new_x / PIXEL_X);
	map_grid_y = (new_y / PIXEL_X);
	if (game->map_2d[map_grid_y][map_grid_x] != '1')
	{
		game->player->pl_pix_x = new_x;
		game->player->pl_pix_y = new_y;
		game->player->pl_map_x = map_grid_x;
		game->player->pl_map_y = map_grid_y;
	}
}

void	update_pos(t_game *game, double move_x, double move_y)
{
	if (game->player->rot >= 1)
		rotate_player(game, 1);
	if (game->player->rot <= -1)
		rotate_player(game, 0);
	if (game->player->l_r == 1)
	{
		move_x = -sin(game->player->ang_dir) * PLAYER_SPEED;
		move_y = cos(game->player->ang_dir) * PLAYER_SPEED;
	}
	if (game->player->l_r == -1)
	{
		move_x = sin(game->player->ang_dir) * PLAYER_SPEED;
		move_y = -cos(game->player->ang_dir) * PLAYER_SPEED;
	}
	if (game->player->u_d == 1)
	{
		move_x = cos(game->player->ang_dir) * PLAYER_SPEED;
		move_y = sin(game->player->ang_dir) * PLAYER_SPEED;
	}
	if (game->player->u_d == -1)
	{
		move_x = -cos(game->player->ang_dir) * PLAYER_SPEED;
		move_y = -sin(game->player->ang_dir) * PLAYER_SPEED;
	}
	move_player(game, move_x, move_y);
}

int	key_release(int keycode)
{
	if (keycode == W)
		game()->player->u_d = 0;
	else if (keycode == S)
		game()->player->u_d = 0;
	else if (keycode == A)
		game()->player->l_r = 0;
	else if (keycode == D)
		game()->player->l_r = 0;
	else if (keycode == LEFT)
		game()->player->rot = 0;
	else if (keycode == RIGHT)
		game()->player->rot = 0;
	return (0);
}

int	key_press(int keycode)
{
	if (keycode == 53)
		return (ft_error_message(2, "EXIT", 11));
	else if (keycode == W)
		game()->player->u_d = 1;
	else if (keycode == S)
		game()->player->u_d = -1;
	else if (keycode == A)
		game()->player->l_r = -1;
	else if (keycode == D)
		game()->player->l_r = 1;
	else if (keycode == LEFT)
		game()->player->rot = -1;
	else if (keycode == RIGHT)
		game()->player->rot = 1;
	return (0);
}

int	mouse_move(int keycode)
{
	static int	last_x = (SCREEN_WIDTH / 2);
	float		delta_x;
	float		angle;

	delta_x = keycode - last_x;
	angle = delta_x * ROTATION_SPEED * 0.4;
	game()->player->ang_dir += angle;
	if (game()->player->ang_dir > 2 * M_PI)
		game()->player->ang_dir -= 2 * M_PI;
	if (game()->player->ang_dir > 2 * M_PI)
		game()->player->ang_dir -= 2 * M_PI;
	last_x = keycode;
	return (0);
}
