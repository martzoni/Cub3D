/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:17:34 by mmasoni           #+#    #+#             */
/*   Updated: 2024/03/18 12:39:29 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cardinal_char(char c)
{
	if (c == 'N')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'S')
		return (0);
	else if (c == 'W')
		return (0);
	return (1);
}

int	not_a_wall(char c)
{
	if (!cardinal_char(c))
		return (0);
	if (c == '0')
		return (0);
	return (1);
}

int	cardinal_counter(char **map2d)
{
	int	x;
	int	y;
	int	counter;

	y = 0;
	counter = 0;
	while (map2d[y])
	{
		x = 0;
		while (map2d[y][x])
		{
			if (!cardinal_char(map2d[y][x]))
			{
				game()->x_player = x;
				game()->y_player = y;
				game()->direc_player = map2d[y][x];
				counter++;
			}
			x++;
		}
		y++;
	}
	if (counter != 1)
		return (1);
	return (0);
}

int	rounded_by_wall(char **map2d)
{
	int	x;
	int	y;

	y = 0;
	while (map2d[y])
	{
		x = 0;
		while (map2d[y][x])
		{
			if (!not_a_wall(map2d[y][x]))
			{
				if (x == game()->x_len -1 || x == 0)
					return (1);
				if (y == game()->y_len - 1 || y == 0)
					return (1);
				if (map2d[y][x + 1] == ' ' || map2d[y][x - 1] == ' ')
					return (1);
				if (map2d[y + 1][x] == ' ' || map2d[y - 1][x] == ' ')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
