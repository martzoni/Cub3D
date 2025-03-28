/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:06:33 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/17 10:22:49 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr_dst;
	unsigned const char	*ptr_src;

	if (!dst && !src)
		return (0);
	ptr_dst = dst;
	ptr_src = src;
	while (n--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}

// #include <stdio.h>

// int main(){
// 	const char src[50] = "";
// 	char dest[50] = "Heloooo!!";
// 	printf("Before memcpy dest = %s\n", dest);
// 	ft_memcpy(dest, src, 5);
// 	printf("After memcpy dest = %s\n", dest);

// 	return(0);
// }
