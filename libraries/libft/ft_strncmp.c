/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:08:51 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/17 10:28:23 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
// 	const char s1[] = "test\200";
// 	const char s2[] = "test\0";
// 	unsigned int n = 6;
// 	int ret = 0;

// 	ret = ft_strncmp(s1, s2, n);
// 	printf("ft_strncmp |%s| is - |%i|\n", s1, ret);
// 	ret = strncmp(s1, s2, n);
// 	printf("strncmp    |%s| is - |%i|\n", s1, ret);

// 	return(0);
// }