/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:14:43 by mmasoni           #+#    #+#             */
/*   Updated: 2024/03/25 09:01:18 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	longest_line(char **map2d)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	len = 1;
	while (map2d[y])
	{
		x = 0;
		while (map2d[y][x])
		{
			if (map2d[y][x] != '\n' && len <= x)
				len++;
			x++;
		}
		y++;
	}
	game()->x_len = len;
	game()->y_len = y;
}

char	*fix_line(char *line)
{
	char	*temp_line;
	int		x;

	temp_line = ft_calloc(1, game()->x_len + 1);
	x = 0;
	while (line[x] != '\n' && line[x] != '\0')
	{
		temp_line[x] = line[x];
		x++;
	}
	while (x < game()->x_len)
	{
		temp_line[x] = ' ';
		x++;
	}
	temp_line[x] = '\0';
	free(line);
	return (temp_line);
}

void	fix_map2d(char **map2d)
{
	int	y;

	y = 0;
	while (map2d[y])
	{
		map2d[y] = fix_line(map2d[y]);
		y++;
	}
}

int	parse_map(void)
{
	if (game()->line == NULL)
		return (ft_error_message(2, "Empty map", 1));
	game()->map_2d = ft_split("", '\0');
	while (game()->line && game()->line[0] != '\n')
	{
		if (game()->line[0] != '1' && game()->line[0] != ' ')
			return (ft_error_message(2, "Error map char", 1));
		add_word(&game()->map_2d, game()->line);
		free(game()->line);
		game()->line = get_next_line(game()->fd);
	}
	if (cardinal_counter(game()->map_2d))
		return (ft_error_message(2, "Missing player", 1));
	longest_line(game()->map_2d);
	fix_map2d(game()->map_2d);
	if (rounded_by_wall(game()->map_2d))
		return (ft_error_message(2, "Map not closed", 1));
	if (game()->x_len < 3 || game()->y_len < 3)
		return (ft_error_message(2, "Map to small", 1));
	return (0);
}
