/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:43:53 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/17 10:32:06 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *hs, const char *ne, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
