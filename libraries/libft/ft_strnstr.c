/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:09:21 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/31 14:20:39 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ne, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen(ne) <= 0)
		return ((char *)hs);
	while (hs[i] != '\0' && i < len)
	{
		j = 0;
		while (hs[i + j] == ne[j] && i + j < len)
		{
			if (ne[j + 1] == '\0')
				return ((char *)hs + i);
			j++;
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	char * ret;

// 	ret = ft_strnstr(haystack, needle, -1);
// 	printf("|%s|\n", ret);
// 	ret = ft_strnstr(haystack, "abcd", 19);
// 	printf("|%s|\n", ret);
// 	return (0);
// }
