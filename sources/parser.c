/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:38:10 by mmasoni           #+#    #+#             */
/*   Updated: 2024/04/04 09:26:07 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_extension(char *file)
{
	char	*dot;

	dot = ft_strchr(file, '.');
	if (ft_strncmp(dot, ".cub", 5))
		return (1);
	return (0);
}

int	open_file(char *file)
{
	int	fd;

	if (check_extension(file))
		return (ft_error_message(2, "Wrong extension", 1));
	fd = open(file, O_RDONLY);
	game()->fd = fd;
	if (game()->fd < 0)
		return (ft_error_message(2, "Impossible to open file", 1));
	if (parse_txtr())
		return (1);
	game()->line = get_next_line(game()->fd);
	while (game()->line && game()->line[0] == '\n')
	{
		free(game()->line);
		game()->line = get_next_line(game()->fd);
	}
	if (parse_map())
		return (1);
	return (0);
}
