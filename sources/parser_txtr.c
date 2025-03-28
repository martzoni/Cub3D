/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_txtr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:48:45 by mmasoni           #+#    #+#             */
/*   Updated: 2024/03/28 13:49:26 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_txtgr_id(char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (NO);
	else if (!ft_strncmp(line, "SO", 2))
		return (SO);
	else if (!ft_strncmp(line, "WE", 2))
		return (WE);
	else if (!ft_strncmp(line, "EA", 2))
		return (EA);
	else if (!ft_strncmp(line, "F", 1))
		return (F);
	else if (!ft_strncmp(line, "C", 1))
		return (C);
	else
		return (EMPTY);
}

int	new_texture(char *line)
{
	int	i;

	i = get_txtgr_id(line);
	if (i == EMPTY)
		return (1);
	if (game()->a_txtr[i].key)
		return (ft_error_message(2, "Duplicate texture", 10));
	if (i >= NO && i <= WE)
	{
		game()->a_txtr[i].key = ft_substr(line, 0, 2);
		line += 2;
		while (*line == ' ')
			line++;
		game()->a_txtr[i].value = ft_strdup(line);
	}
	else if (i == C || i == F)
	{
		game()->a_txtr[i].key = ft_substr(line, 0, 1);
		line += 1;
		while (*line == ' ')
			line++;
		game()->a_txtr[i].value = ft_strdup(line);
	}
	game()->a_txtr[i].id = i;
	// printf("textr : %s - %s\n", game()->a_txtr[i].key, game()->a_txtr[i].value );
	return (0);
}

int	parse_txtr(void)
{
	game()->line = get_next_line(game()->fd);
	if (game()->line == NULL)
		return (ft_error_message(2, "Empty file", 1));
	while (a_txtr_len(game()->a_txtr) < 6 && game()->line)
	{
		// printf("count : %i\n", a_txtr_len(game()->a_txtr));
		if (game()->line[0] == '1' && game()->line[0] == ' ')
			return (ft_error_message(2, "Empty file", 1));
		new_texture(game()->line);
		free(game()->line);
		game()->line = get_next_line(game()->fd);
	}
	valid_txtr();
	return (0);
}
