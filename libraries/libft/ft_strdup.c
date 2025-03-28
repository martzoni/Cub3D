/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:54:48 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/16 13:59:46 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (copy != NULL)
	{
		while (s1[i] != '\0')
		{
			copy[i] = s1[i];
			++i;
		}
		copy[i] = '\0';
	}
	return (copy);
}
