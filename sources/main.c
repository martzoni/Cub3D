/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:33:30 by martinmason       #+#    #+#             */
/*   Updated: 2024/03/27 09:41:47 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error_message(2, "Wrong args number", 1));
	open_file(argv[1]);
	init();
	return (0);
}
