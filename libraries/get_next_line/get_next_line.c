/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:42:58 by mmasoni           #+#    #+#             */
/*   Updated: 2023/11/27 14:56:28 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_free(char *superbuffer, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(superbuffer, buffer);
	free(superbuffer);
	return (temp);
}

size_t	check_breaker(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)0);
}

char	*gen_superbuffer(int fd, char *superbuffer)
{
	int		result;
	char	*buffer;

	if (!superbuffer)
		superbuffer = ft_calloc(1, 1);
	if (!superbuffer)
		return (0);
	result = 1;
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (result > 0)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		buffer[result] = '\0';
		if (result < 0)
			break ;
		superbuffer = ft_free(superbuffer, buffer);
		if (ft_strchr(superbuffer, '\n'))
			break ;
	}
	free(buffer);
	return (superbuffer);
}

char	*get_next_line(int fd)
{
	static char			*superbuffer;
	unsigned int		breaker_i;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(superbuffer);
		superbuffer = 0;
		return (0);
	}
	if (!superbuffer || !ft_strchr(superbuffer, '\n'))
		superbuffer = gen_superbuffer(fd, superbuffer);
	if (!superbuffer)
		return (0);
	breaker_i = check_breaker(superbuffer);
	if (superbuffer[0] == '\0')
	{
		free (superbuffer);
		superbuffer = 0;
		return (0);
	}
	line = sub_str(superbuffer, 0, breaker_i + 1);
	superbuffer = sub_str(superbuffer, breaker_i + 1, ft_strlen(superbuffer));
	return (line);
}

// int	main(void)
// {
// 	const char	*path = "livre";
// 	int			fd;
// 	int			i;
// 	char 		*line;

// 	i = 0;
// 	fd = open(path, O_RDONLY);
// 	while (i < 27)
// 	{
// 		line = get_next_line(fd);
// 		printf("\033[0;31m");
// 		printf("%iº *%s#",i + 1, line);
// 		printf("\033[0m");
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
