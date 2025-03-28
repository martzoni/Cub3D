/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_txtr_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:48:45 by mmasoni           #+#    #+#             */
/*   Updated: 2024/04/04 09:27:31 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	a_txtr_len(t_txtr a_txtr[6])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 6)
	{
		if (a_txtr[i].key)
			count++;
		i++;
	}
	return (count);
}

int	valid_rgb_virgules(char *rgb)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (rgb[i])
		if (rgb[i++] == ',')
			count++;
	if (count != 2)
		return (1);
	return (0);
}

unsigned long	rgb_to_hex(char *red, char *green, char *blue)
{
	return (((ft_atoi(red) & 0xff) << 16) + \
		((ft_atoi(green) & 0xff) << 8) + (ft_atoi(blue) & 0xff));
}

int	valid_rgb(t_txtr *txtr)
{
	int		i;
	char	**rgb_2d;

	i = 0;
	rgb_2d = ft_split(txtr->value, ',');
	while (rgb_2d[i])
	{
		if (ft_atoi(rgb_2d[i]) < 0 || ft_atoi(rgb_2d[i]) > 255)
		{
			free_2d(rgb_2d);
			return (1);
		}
		i++;
	}
	if (i != 3)
	{
		free_2d(rgb_2d);
		return (1);
	}
	if (!ft_strncmp(txtr->key, "C", 2))
		game()->cc = rgb_to_hex(rgb_2d[0], rgb_2d[1], rgb_2d[2]);
	if (!ft_strncmp(txtr->key, "F", 2))
		game()->ff = rgb_to_hex(rgb_2d[0], rgb_2d[1], rgb_2d[2]);
	return (0);
}

void	fix_txtr(t_txtr a_txtr[6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (a_txtr[i].value[j])
		{
			if (a_txtr[i].value[j] == '\n')
			{
				a_txtr[i].value[j] = '\0';
				break ;
			}
			j++;
		}
		i++;
	}
}

int	valid_txtr(void)
{
	if (a_txtr_len(game()->a_txtr) != 6)
		return (ft_error_message(2, "Wrong texture", 10));
	fix_txtr(game()->a_txtr);
	if (valid_rgb(&game()->a_txtr[C]))
		return (ft_error_message(2, "Wrong RGB", 19));
	if (valid_rgb(&game()->a_txtr[F]))
		return (ft_error_message(2, "Wrong RGB", 19));
	return (0);
}
