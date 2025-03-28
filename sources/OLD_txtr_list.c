/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_txtr_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:37:40 by mmasoni           #+#    #+#             */
/*   Updated: 2024/03/27 16:21:43 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// float	fix_angle(float angle)
// {
// 	if (angle < 0)
// 		angle += (2 * M_PI);
// 	if (angle > (2 * M_PI))
// 		angle -= (2 * M_PI);
// 	return (angle);
// }

// int	unit_circle(float angle, char c)
// {
// 	if (c == 'x')
// 	{
// 		if (angle > 0 && angle < M_PI)
// 			return (1);
// 	}
// 	else if (c == 'y')
// 	{
// 		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
// 			return (1);
// 	}
// 	return (0);
// }

// int	inter_check(float angle, float *inter, float *step, int is_horizon)
// {
// 	if (is_horizon)
// 	{
// 		if (angle > 0 && angle < M_PI)
// 		{
// 			*inter += PIXEL_X;
// 			return (-1);
// 		}
// 		*step *= -1;
// 	}
// 	else
// 	{
// 		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
// 		{
// 			*inter += PIXEL_X;
// 			return (-1);
// 		}
// 		*step *= -1;
// 	}
// 	return (1);
// }

// int	wall_hit(t_game *game, float x_curr, float y_curr)
// {
// 	int		x_map;
// 	int		y_map;

// 	if (x_curr < 0 || y_curr < 0)
// 		return (0);
// 	x_map = floor (x_curr / PIXEL_X);
// 	y_map = floor (y_curr / PIXEL_X);
// 	if ((y_map >= game->y_len || x_map >= game->x_len))
// 		return (0);
// 	if (game->map_2d[y_map] && x_map <= (int)ft_strlen(game->map_2d[y_map]))
// 		if (game->map_2d[y_map][x_map] == '1')
// 		{
// 			printf("y_map : %d | x_map : %d ", y_map, x_map);
// 			return (0);
// 		}
// 	return (1);
// }

// double	get_y_inter(t_game *game, double angle)
// {
// 	float	x_curr;
// 	float	y_curr;
// 	float	x_step;
// 	float	y_step;
// 	int		pixel;

// 	y_step = PIXEL_X;
// 	x_step = PIXEL_X / tan(angle);
// 	// printf("x_step : %f  / ", x_step);
// 	y_curr = floor(game->player->pl_pix_y / PIXEL_X) * PIXEL_X;
// 	pixel = inter_check(angle, &y_curr, &y_step, 1);
// 	x_curr = game->player->pl_pix_x + (y_curr - game->player->pl_pix_y) / tan(angle);
// 	// printf("x_step : %f         ", x_step);
// 	if ((unit_circle(angle, 'y') && x_step > 0) || \
// 		(!unit_circle(angle, 'y') && x_step < 0))
// 		x_step *= -1;
// 	// printf("y_curr : %f | x_curr : %f         ", y_curr, x_curr);
// 	// while (wall_hit(game, x_curr, y_curr - pixel))
// 	// {
// 	// 	x_curr += x_step;
// 	// 	y_curr += y_step;
// 	// }
// 	// printf("      y_curr : %f | x_curr : %f\n", y_curr, x_curr);
// 	game->ray->horiz_x = x_curr;
// 	game->ray->horiz_y = y_curr;
// 	return (sqrt(pow(x_curr - game->player->pl_pix_x, 2) + \
// 	pow(y_curr - game->player->pl_pix_y, 2)));
// 	return (0);
// }

// double	get_x_inter(t_game *game, double angle)
// {
// 	float	x_curr;
// 	float	y_curr;
// 	float	x_step;
// 	float	y_step;
// 	int		pixel;

// 	x_step = PIXEL_X;
// 	y_step = PIXEL_X / tan(angle);
// 	printf("y_step : %f  / ", y_step);
// 	x_curr = floor(game->player->pl_pix_x / PIXEL_X) * PIXEL_X;
// 	// printf("x_curr : %f         ", x_curr);
// 	pixel = inter_check(angle, &x_curr, &x_step, 0);
// 	y_curr = game->player->pl_pix_y + (x_curr - game->player->pl_pix_x) * tan(angle);
// 	if ((unit_circle(angle, 'x') && y_step < 0) || \
// 	(!unit_circle(angle, 'x') && y_step > 0))
// 		y_step *= -1;
// 	printf("y_step : %f         ", y_step);
// 	printf("y_curr : %f | x_curr : %f         ", y_curr, x_curr);
// 	while (wall_hit(game, x_curr - pixel, y_curr))
// 	{
// 		x_curr += x_step;
// 		y_curr += y_step;
// 	}
// 	printf("      y_curr : %f | x_curr : %f\n", y_curr, x_curr);
// 	game->ray->horiz_x = x_curr;
// 	game->ray->horiz_y = y_curr;
// 	return (sqrt(pow(x_curr - game->player->pl_pix_x, 2) + \
// 	pow(y_curr - game->player->pl_pix_y, 2)));
// 	return (0);
// }


// ----------------

// float	fix_angle(float angle)
// {
// 	if (angle < 0)
// 		angle += (2 * M_PI);
// 	if (angle > (2 * M_PI))
// 		angle -= (2 * M_PI);
// 	return (angle);
// }

// void	adapt_step_dir(float angle, float *y_step, float *x_step)
// {
// 	if (angle > M_PI && *y_step > 0)
// 		*y_step *= -1;
// 	if ((angle > (M_PI / 2) && angle < (3 * M_PI) / 2) ||  *x_step < 0)
// 	{
// 		printf("😊");
// 		*x_step *= -1;
// 	}
// }

// int	inter_check(float angle, float *point_curr, int is_horizon)
// {
// 	if (is_horizon && angle < M_PI)
// 	{
// 		*point_curr += PIXEL_X;
// 		return (-1);
// 	}
// 	else if (!(is_horizon) && (angle > 3 * M_PI / 2 && angle < M_PI / 2))
// 	{
// 		*point_curr += PIXEL_X;
// 		return (-1);
// 	}
// 	return (1);
// }

// int	wall_hit(t_game *game, float x_curr, float y_curr)
// {
// 	int		x_map;
// 	int		y_map;

// 	if (x_curr < 0 || y_curr < 0)
// 		return (0);
// 	x_map = floor (x_curr / PIXEL_X);
// 	y_map = floor (y_curr / PIXEL_X);
// 	if ((y_map >= game->y_len || x_map >= game->x_len))
// 		return (0);
// 	if (game->map_2d[y_map] && x_map <= (int)ft_strlen(game->map_2d[y_map]))
// 		if (game->map_2d[y_map][x_map] == '1')
// 		{
// 			printf("y_map : %d | x_map : %d ", y_map, x_map);
// 			return (0);
// 		}
// 	return (1);
// }

// double	get_y_inter(t_game *game, double angle)
// {
// 	float	x_curr;
// 	float	y_curr;
// 	float	x_step;
// 	float	y_step;
// 	int		pixel;

// 	y_step = PIXEL_X;
// 	x_step = PIXEL_X / tan(angle);
// 	// printf("x_step : %f  / ", x_step);
// 	y_curr = floor(game->player->pl_pix_y / PIXEL_X) * PIXEL_X;
// 	x_curr = game->player->pl_pix_x + (y_curr - game->player->pl_pix_y) / tan(angle);
// 	adapt_step_dir(angle, &y_step, &x_step);
// 	// printf("x_step : %f         ", x_step);
// 	pixel = inter_check(angle, &y_curr, 1);
// 	// printf("y_curr : %f | x_curr : %f         ", y_curr, x_curr);
// 	// while (wall_hit(game, x_curr, y_curr - pixel))
// 	// {
// 	// 	x_curr += x_step;
// 	// 	y_curr += y_step;
// 	// }
// 	// printf("      y_curr : %f | x_curr : %f\n", y_curr, x_curr);
// 	game->ray->horiz_x = x_curr;
// 	game->ray->horiz_y = y_curr;
// 	return (sqrt(pow(x_curr - game->player->pl_pix_x, 2) + \
// 	pow(y_curr - game->player->pl_pix_y, 2)));
// 	return (0);
// }

//-----------------
// void show_txtr(void)
// {
// 	t_txtr *temp;

// 	temp = game()->l_txtr;
// 	while (temp)
// 	{
// 		printf("Key : %s | Value : %s\n", temp->key, temp->value);
// 		temp = temp->next;
// 	}
// }

// int l_txtr_len(t_txtr *l_txtr)
// {
// 	int i;
// 	t_txtr *temp;

// 	i = 0;
// 	temp = l_txtr;
// 	while (temp)
// 	{
// 		temp = temp->next;
// 		i++;
// 	}
// 	return (i);
// }

// t_txtr *new_texture(char *line)
// {
// 	t_txtr *new_txtr;

// 	new_txtr = (t_txtr *)ft_calloc(sizeof(t_txtr), 1);
// 	if (!new_txtr)
// 		return (NULL);
// 	if ((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)))
// 	{
// 		new_txtr->key = ft_substr(line, 0, 2);
// 		line += 2;
// 		while (*line == ' ')
// 			line++;
// 		new_txtr->value = ft_strdup(line);
// 	}
// 	else if ((!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1)))
// 	{
// 		new_txtr->key = ft_substr(line, 0, 1);
// 		line += 1;
// 		while (*line == ' ')
// 			line++;
// 		new_txtr->value = ft_strdup(line);
// 	}
// 	else if (!ft_strncmp(line, "\n", 2))
// 		new_txtr->value = ft_strdup(line);
// 	return (new_txtr);
// }

// int parse_txtr(void)
// {
// 	game()->line = get_next_line(game()->fd);
// 	if (game()->line == NULL)
// 		return (ft_error_message(2, "Empty file", 1));
// 	while (l_txtr_len(game()->l_txtr) != 6 && game()->line)
// 	{
// 		if (game()->line[0] == '1' && game()->line[0] == ' ')
// 			return (ft_error_message(2, "Empty file", 1));
// 		game()->temp_txtr = new_texture(game()->line);
// 		if (!game()->temp_txtr)
// 			return (0);
// 		if (game()->temp_txtr->key == NULL && !game()->temp_txtr->value)
// 			return (ft_error_message(2, "Error texture file", 12));
// 		if (game()->temp_txtr->key == NULL)
// 		{
// 			free(game()->temp_txtr->value);
// 			free(game()->temp_txtr);
// 		}
// 		else
// 			add_txtr(&game()->l_txtr, game()->temp_txtr);
// 		free(game()->line);
// 		game()->line = get_next_line(game()->fd);
// 	}
// 	valid_txtr();
// 	return (0);
// }

// int	valid_txtr(void)
// {
// 	if (l_txtr_len(game()->l_txtr) != 6)
// 		return (ft_error_message(2, "Wrong texture", 10));
// 	if (unique_txtr(&game()->l_txtr))
// 		return (ft_error_message(2, "Duplicate texture", 10));
// 	return (0);
// }

// int	unique_txtr(t_txtr **l_txtr)
// {
// 	t_txtr	*temp;
// 	t_txtr	*temp2;
// 	char	*key;

// 	temp = *l_txtr;
// 	while (temp)
// 	{
// 		key = temp->key;
// 		if (key[0] == 'F' || key[0] == 'C')
// 			if (valid_rgb(temp->value))
// 				return (ft_error_message(2, "Wrong RGB", 19));
// 		temp2 = temp->next;
// 		while (temp2)
// 		{
// 			if (!ft_strncmp(key, temp2->key, ft_strlen(key)))
// 				return (1);
// 			temp2 = temp2->next;
// 		}
// 		temp = temp->next;
// 	}
// 	return (0);
// }

// void add_txtr(t_txtr **l_txtr, t_txtr *new_txtr)
// {
// 	t_txtr *temp;

// 	temp = *l_txtr;
// 	if (!temp)
// 	{
// 		*l_txtr = new_txtr;
// 		return;
// 	}
// 	while (temp->next)
// 		temp = temp->next;
// 	temp->next = new_txtr;
// }
