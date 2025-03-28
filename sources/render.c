/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:01:01 by mmasoni           #+#    #+#             */
/*   Updated: 2024/04/04 11:15:10 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	game_place_pixel(int x, int y, int colour)
{
	char	*distance;

	distance = game()->frame->address_char + (y * game()->frame->line_length \
		+ x * (game()->frame->bits_per_pixel / 8));
	*(unsigned int *)distance = colour;
}

void	draw_thick_point(int x, int y, int thickness)
{
	int	j;
	int	k;

	j = -thickness / 2;
	while (j <= thickness / 2)
	{
		k = -thickness / 2;
		while (k <= thickness / 2)
		{
			if (x + j < BORDER + 110 && y + k < BORDER + 110 \
				&& x + j >= BORDER && y + k >= BORDER)
				game_place_pixel(x + j, y + k, 14626086);
			k++;
		}
		j++;
	}
}

void	draw_line(t_game *game, int pix_x, int pix_y)
{
	double	step_x;
	double	step_y;
	int		length;
	int		i;

	step_x = cos(game->player->ang_dir);
	step_y = sin(game->player->ang_dir);
	length = floor (game->map_distance / 64 * 10);
	i = 1;
	draw_thick_point(pix_x, pix_y, 2);
	while (i <= length)
	{
		draw_thick_point(pix_x + (int)(i * step_x), \
			pix_y + (int)(i * step_y), 2);
		i++;
	}
}

void	print_player(void)
{
	int	x_pix;
	int	y_pix;
	int	x;
	int	y;

	x_pix = BORDER + 51;
	y_pix = BORDER + 51;
	draw_line(game(), x_pix + 4, y_pix + 4);
	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			game_place_pixel(x_pix + x, y_pix + y, 14626086);
			x++;
		}
		y++;
	}
}

void	mini_map_x(int x_map, int y_map, int x_pix, int y_pix)
{
	if ((y_map < 0 || x_map < 0) || \
		(y_map >= game()->y_len || x_map >= game()->x_len))
		game_place_pixel(x_pix + BORDER, y_pix + BORDER, 3026478);
	else if (game()->map_2d[y_map][x_map] && \
		not_a_wall(game()->map_2d[y_map][x_map]) == 0)
		game_place_pixel(x_pix + BORDER, y_pix + BORDER, 13619151);
	else
		game_place_pixel(x_pix + BORDER, y_pix + BORDER, 3026478);
}

void	mini_map(t_game *game)
{
	int	x_map;
	int	y_map;
	int	x_pix;
	int	y_pix;

	y_pix = 0;
	while (y_pix < 110)
	{
		y_map = roundf (((double)game->player->pl_pix_y / PIXEL_X) \
			- 6 + ((double)y_pix / 10));
		x_pix = 0;
		while (x_pix < 110)
		{
			x_map = roundf (((double)game->player->pl_pix_x / PIXEL_X) \
				- 6 + ((double)x_pix / 10));
			mini_map_x(x_map, y_map, x_pix, y_pix);
			x_pix++;
		}
		y_pix++;
	}
	// print_player(game);
}

void	draw_floor(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT / 2 - 1;
		while (++j < SCREEN_HEIGHT)
			game_place_pixel(i, j, game()->ff);
		i++;
	}
}

void	draw_ceiling(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT / 2)
			game_place_pixel(i, j, game()->cc);
		i++;
	}
}

t_txtr	*get_texture(t_game *game, int flag)
{
	game->ray->curr_angle = fix_angle(game->ray->curr_angle);
	if (flag == 0)
	{
		if (game->ray->curr_angle > M_PI / 2 \
			&& game->ray->curr_angle < 3 * (M_PI / 2))
			return (&game->a_txtr[EA]);
		else
			return (&game->a_txtr[WE]);
	}
	else
	{
		if (game->ray->curr_angle > 0 && game->ray->curr_angle < M_PI)
			return (&game->a_txtr[SO]);
		else
			return (&game->a_txtr[NO]);
	}
}

double	get_x_o(t_txtr	*texture, t_game *game)
{
	double	x_o;

	if (game->ray->flag == 1)
		x_o = (int)fmodf(game->ray->horiz_x, texture->width);
	else
		x_o = (int)fmodf(game->ray->vert_y, texture->width);
	return (x_o);
}

void draw_scope(t_game *game, int pix_x, int pix_y)
{
	double step_x;
	double step_y;
	int length;
	int i;

	step_x = cos(game->ray->curr_angle);
	step_y = sin(game->ray->curr_angle);
	length = (game->ray->distance * 10 / 64);
	if (length > 35)
		length = 35;
	i = 1;
	// draw_thick_point(pix_x, pix_y, 1);
	while (i <= length)
	{
		// pix_x = pix_x + (int)(i * step_x);
		// pix_y = pix_y + (int)(i * step_y);
		if ((pix_x + (int)(i * step_x)) < BORDER + 110 && (pix_y + (int)(i * step_y)) < BORDER + 110 && (pix_x + (int)(i * step_x)) >= BORDER && (pix_y + (int)(i * step_y)) >= BORDER)
			game_place_pixel((pix_x + (int)(i * step_x)), (pix_y + (int)(i * step_y)), 15109003);
		i++;
	}
}

void	draw_wall(t_game *game, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	t_txtr			*texture;
	double			factor;

	texture = NULL;
	texture = get_texture(game, game->ray->flag);
	factor = (double)texture->height / wall_h;
	x_o = get_x_o(texture, game);
	y_o = (t_pix - (SCREEN_HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		if (!(game->ray->index >= 25 && game->ray->index < 135 && t_pix >= 25 && t_pix < 135))
				game_place_pixel(game->ray->index, t_pix,
							 (game->txtr_3d[texture->id][(int)y_o][(int)x_o]));
		y_o += factor;
		t_pix++;
	}
	draw_scope(game, BORDER + 55, BORDER + 55);
}

void	render_wall(t_game *game, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	game->ray->distance *= cos(fix_angle(game->ray->curr_angle \
		- game->player->ang_dir));
	if (game->ray->distance == 0)
		game->ray->distance += 1;
	wall_h = (PIXEL_X / game->ray->distance) * ((SCREEN_WIDTH / 2) / \
	tan(game->player->ang_fov / 2));
	b_pix = (SCREEN_HEIGHT / 2) + (wall_h / 2);
	t_pix = (SCREEN_HEIGHT / 2) - (wall_h / 2);
	if (b_pix > SCREEN_HEIGHT)
		b_pix = SCREEN_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	game->ray->index = ray;
	draw_wall(game, t_pix, b_pix, wall_h);
}
