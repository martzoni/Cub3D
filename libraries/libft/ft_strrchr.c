/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:58:48 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/16 13:58:20 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return ((char *)0);
}

// #include <stdio.h>

// int main ()
// { 
//    const char str[] = "coucocu";
//    const char ch = '\0';
//    char *ret;

//    ret = ft_strrchr(str, ch);

//    printf("String after |%c| is - |%s|\n", ch, ret);

//    return(0);
// }