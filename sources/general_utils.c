/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:45:00 by mmasoni           #+#    #+#             */
/*   Updated: 2024/04/04 09:28:47 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

void	free_2d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_error_message(int fd, char *message, int ret)
{
	int	len;

	len = ft_strlen(message);
	write(fd, message, len);
	write(fd, "\n", 1);
	if (ret > 9)
		exit (ret);
	return (ret);
}

void	show_txtr(void)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		printf("Key : %s | Value : %s\n", \
			game()->a_txtr[i].key, game()->a_txtr[i].value);
		i++;
	}
}

void	show_map(void)
{
	int	i;

	i = 0;
	while (game()->map_2d[i])
	{
		printf("%i : %s\n", i, game()->map_2d[i]);
		i++;
	}
	printf("x_len: %i | y_len %i\n", game()->x_len, game()->y_len);
	printf("x_player: %i | y_player %i | direc_player %c\n", \
		game()->x_player, game()->y_player, game()-> direc_player);
}

void	add_word(char ***tab, char *word)
{
	char	**tmp_tab;
	int		i;
	int		size;

	size = 0;
	if (*tab)
		while ((*tab)[size])
			size++;
	tmp_tab = (char **)malloc(sizeof(char *) * (size + 2));
	if (!tmp_tab)
		return ;
	i = 0;
	while (i < size)
	{
		tmp_tab[i] = (*tab)[i];
		i++;
	}
	tmp_tab[i] = ft_strdup(word);
	tmp_tab[i + 1] = NULL;
	if (*tab)
		free(*tab);
	*tab = tmp_tab;
}
