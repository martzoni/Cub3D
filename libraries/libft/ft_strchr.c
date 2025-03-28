/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:32:22 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/12 15:02:47 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)0);
}

// #include <stdio.h>

// int main ()
// { 
//    const char str[] = "tripouille";
//    const char ch = 'p';
//    char *ret;

//    ret = ft_strchr(str, ch + 256);

//    printf("String after |%c| is - |%s|\n", ch, ret);

//    return(0);
// }