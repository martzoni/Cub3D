/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:30:03 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/17 10:22:56 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	unsigned const char	*ptr_src;

	if (!dst && !src)
		return (0);
	ptr_dst = dst;
	ptr_src = src;
	if (ptr_dst < ptr_src)
	{
		while (len--)
			*ptr_dst++ = *ptr_src++;
	}
	else
	{
		ptr_dst = dst + (len - 1);
		ptr_src = src + (len - 1);
		while (len--)
			*ptr_dst-- = *ptr_src--;
	}
	return (dst);
}

// #include <stdio.h>

// int main(){
// 	const char src[50] = "https://www.tutorialspoint.com";
// 	char dest[50] = "Heloooo!!";
// 	printf("Before memcpy dest = %s\n", dest);
// 	ft_memmove(dest, src, 2);
// 	printf("After memcpy dest = %s\n", dest);

// 	return(0);
// }
