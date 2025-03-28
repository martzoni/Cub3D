/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:28:56 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/24 10:39:59 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	if (!s)
		return ;
	ptr = s;
	while (n-- > 0)
		*ptr++ = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*reserved;

	reserved = malloc(count * size);
	if (!reserved)
	{
		return (0);
	}
	ft_bzero(reserved, size * count);
	return (reserved);
}

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	s1_size;
	unsigned int	s2_size;
	unsigned int	i;

	if (!s1 && !s2)
		return (0);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = malloc (sizeof(char) * (s1_size + s2_size + 1));
	if (!result)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[i - s1_size] != '\0')
	{
		result[i] = s2[i - s1_size];
		i++;
	}
	result[i] = '\0';
	return (result);
}

// ligne 102 spéciale pour le deuxième appel qu'il faut free

char	*sub_str(char *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	s_len;
	size_t			i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	else if (len > (s_len - start))
		len = s_len - start;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	if (start != 0)
		free(s);
	new_str[i] = '\0';
	return (new_str);
}
