/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:47:37 by mmasoni           #+#    #+#             */
/*   Updated: 2024/04/04 09:40:45 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void convert_txtr_3d(int i)
{
	int x;
	int y;

	y = -1;
	while (++y < PIXEL_Y)
	{
		x = -1;
		while (++x < PIXEL_X)
		{
			game()->txtr_3d[i][y][x] = \
				(game()->a_txtr[i].address_int[PIXEL_X * y + x]);
		}

	}
}

int	load_txtr(void)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		game()->a_txtr[i].pointer_to_image = mlx_xpm_file_to_image(\
			game()->mlx, game()->a_txtr[i].value, \
			&(game()->a_txtr[i].width), &(game()->a_txtr[i].height));
		if (!game()->a_txtr[i].pointer_to_image)
		{
			return (ft_error_message(2, "Can't find texture", 11));
		}
		game()->a_txtr[i].address_int = (int *)mlx_get_data_addr(\
			game()->a_txtr[i].pointer_to_image, \
			&game()->a_txtr[i].bits_per_pixel, &game()->a_txtr[i].line_length, \
			&game()->a_txtr[i].endian);
		if (!game()->a_txtr[i].address_int)
			return (1);
		convert_txtr_3d(i);
		mlx_destroy_image(game()->mlx, game()->a_txtr[i].pointer_to_image);
		i++;
	}
	return (0);
}
int	mallokeur(void)
{
	game()->player = malloc (sizeof(t_player));
	game()->frame = malloc (sizeof(t_txtr));
	game()->ray = malloc (sizeof(t_ray));
	if (!game()->player || !game()->frame || !game()->ray)
		return (ft_error_message(2, "Error malloc", 11));
	return (0);
}
void	set_player(t_game *game)
{
	game->player->pl_pix_x = (game->x_player * PIXEL_X) + PIXEL_X / 2;
	game->player->pl_pix_y = (game->y_player * PIXEL_X) + PIXEL_X / 2;

	game->player->ang_fov = (FOV * M_PI / 180);
	if (game->direc_player == 'E')
		game->player->ang_dir = 0;
	if (game->direc_player == 'S')
		game->player->ang_dir = M_PI / 2;
	if (game->direc_player == 'W')
		game->player->ang_dir = M_PI;
	if (game->direc_player == 'N')
		game->player->ang_dir = 3 * M_PI / 2;
	game->player->rot = 0;
	game->player->u_d = 0;
	game->player->l_r = 0;
}

void	init(void)
{
	game()->mlx = mlx_init();
	mallokeur();
	load_txtr();
	set_player(game());
	game()->win = mlx_new_window(game()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	mlx_hook(game()->win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(game()->win, 6, 0, &mouse_move, NULL);
	mlx_hook(game()->win, X_EVENT_KEY_RELEASE, 0, &key_release, NULL);
	mlx_loop_hook(game()->mlx, &launcher, (game()));
	mlx_loop(game()->mlx);
}
