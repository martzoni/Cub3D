/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:54:32 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/17 10:21:23 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*reserved;

	reserved = malloc(count * size);
	if (!reserved)
		return (0);
	ft_bzero(reserved, size * count);
	return (reserved);
}

// #include <stdio.h>

// int main () {
//    int i, n;
//    int *a;

//    printf("Number of elements to be entered:");
//    scanf("%d",&n);

//    a = (int*)ft_calloc(n, sizeof(int));
//    printf("Enter %d numbers:\n",n);
//    for( i=0 ; i < n ; i++ ) {
//       scanf("%d",&a[i]);
//    }

//    printf("The numbers entered are: ");
//    for( i=0 ; i < n ; i++ ) {
//       printf("%d ",a[i]);
//    }
//    free( a );
//    return(0);
// }