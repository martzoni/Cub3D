/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:46:44 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/17 10:21:51 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
// 	int str[7] = {-49, 49, 1, -1, 0, -2, 2};
// 	int ch = -1;
// 	unsigned int n = 7;
// 	void *ret;

// 	ret = memchr(str, ch, n);
// 	printf("String after |%c| is - |%s|\n", ch, (char *)ret);
// 	ret = ft_memchr(str, ch, n);
// 	printf("String after |%c| is - |%s|\n", ch, (char *)ret);

// 	return(0);
// }