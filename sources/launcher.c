/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:13:27 by mmasoni           #+#    #+#             */
/*   Updated: 2024/04/04 11:06:00 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	fix_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int	inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += PIXEL_X;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += PIXEL_X;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(t_game *game, float x_curr, float y_curr)
{
	int		x_map;
	int		y_map;

	if (x_curr < 0 || y_curr < 0)
		return (0);
	x_map = floor (x_curr / PIXEL_X);
	y_map = floor (y_curr / PIXEL_X);
	if ((y_map >= game->y_len || x_map >= game->x_len))
		return (0);
	if (game->map_2d[y_map] && x_map <= (int)ft_strlen(game->map_2d[y_map]))
		if (game->map_2d[y_map][x_map] == '1')
			return (0);
	return (1);
}

double	get_y_inter(t_game *game, double angle)
{
	float	x_curr;
	float	y_curr;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = PIXEL_X;
	x_step = PIXEL_X / tan(angle);
	y_curr = floor(game->player->pl_pix_y / PIXEL_X) * PIXEL_X;
	pixel = inter_check(angle, &y_curr, &y_step, 1);
	x_curr = game->player->pl_pix_x + (y_curr - game->player->pl_pix_y) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0) || \
		(!unit_circle(angle, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(game, x_curr, y_curr - pixel))
	{
		x_curr += x_step;
		y_curr += y_step;
	}
	game->ray->horiz_x = x_curr;
	game->ray->horiz_y = y_curr;
	return (sqrt(pow(x_curr - game->player->pl_pix_x, 2) + \
	pow(y_curr - game->player->pl_pix_y, 2)));
	return (0);
}

double	get_x_inter(t_game *game, double angle)
{
	float	x_curr;
	float	y_curr;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = PIXEL_X;
	y_step = PIXEL_X * tan(angle);
	x_curr = floor(game->player->pl_pix_x / PIXEL_X) * PIXEL_X;
	pixel = inter_check(angle, &x_curr, &x_step, 0);
	y_curr = game->player->pl_pix_y + (x_curr - game->player->pl_pix_x) * tan(angle);
	if ((unit_circle(angle, 'x') && y_step < 0) || \
	(!unit_circle(angle, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(game, x_curr - pixel, y_curr))
	{
		x_curr += x_step;
		y_curr += y_step;
	}
	game->ray->vert_x = x_curr;
	game->ray->vert_y = y_curr;
	return (sqrt(pow(x_curr - game->player->pl_pix_x, 2) + \
	pow(y_curr - game->player->pl_pix_y, 2)));
	return (0);
}

void	cast_rays(t_game *game)
{
	double	y_inter;
	double	x_inter;
	int		ray;

	ray = 0;
	game->ray->curr_angle = game->player->ang_dir - (game->player->ang_fov / 2);
	while (ray < SCREEN_WIDTH)
	{
		game->ray->flag = 0;
		game->ray->curr_angle = fix_angle(game->ray->curr_angle);
		y_inter = get_y_inter(game, game->ray->curr_angle);
		x_inter = get_x_inter(game, game->ray->curr_angle);
		if (x_inter <= y_inter)
		{
			game->ray->distance = x_inter;
			if (ray == SCREEN_WIDTH / 2)
				game->map_distance = x_inter;
		}
		else
		{
			game->ray->distance = y_inter;
			game->ray->flag = 1;
			if (ray == SCREEN_WIDTH / 2)
				game->map_distance = y_inter;
		}
		render_wall(game, ray);
		ray++;
		game->ray->curr_angle += (game->player->ang_fov / SCREEN_WIDTH);
	}
}

int	launcher(t_game *cur_game)
{
	t_game	*game;

	game = cur_game;
	game->frame->pointer_to_image = mlx_new_image(game->mlx, \
			SCREEN_WIDTH, SCREEN_HEIGHT);
	game->frame->address_char = mlx_get_data_addr(\
			game->frame->pointer_to_image, \
			&game->frame->bits_per_pixel, &game->frame->line_length, \
			&game->frame->endian);
	update_pos(game, 0, 0);
	draw_floor();
	draw_ceiling();
	mini_map(game);
	cast_rays(game);
	print_player();
	mlx_put_image_to_window(game->mlx, game->win, \
		game->frame->pointer_to_image, 0, 0);
	mlx_destroy_image(game->mlx, game->frame->pointer_to_image);
	return (0);
}
