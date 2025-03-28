/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:50:33 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/17 10:20:16 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = '\0';
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char *str = argv[1];
// 	(void)argc;
// 	ft_bzero(str, 3);
// 	printf("sdfhsd");
// 	printf("%s dfg", str);
// 	return (0);
// }