/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:53:10 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/17 10:23:25 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char *str = argv[1];
// 	(void)argc;
// 	printf("%s", ft_memset(str, 'F', 3));
// 	return (0);
// }