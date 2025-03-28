/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:45:45 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/17 10:24:39 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	srclen;

	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	i = 0;
	if (dstsize <= 0)
		return (srclen);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

// #include <stdio.h>
// #include <string.h>

// int main(){
// 	const char src[50] = "lorem ipsum dolor sit amet";
// 	char dest[14] = "";
// 	unsigned int size = 0;
// 	unsigned int result = 0;
// 	result = strlcpy(dest, src, size);
// 	printf("strlcpy    dest = %s | %i\n", dest, result);
// 	result = ft_strlcpy(dest, src, size);
// 	printf("ft_strlcpy dest = %s | %i\n", dest, result);

// 	return(0);
// }
