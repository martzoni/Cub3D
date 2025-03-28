/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:47:09 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/26 14:27:53 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check_next(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	check_error(int len, int len_added)
{
	if (len == -1 || len_added == -1)
		return (-1);
	return (len + len_added);
}

int	ft_putchar(char c)
{
	int	res;

	res = write (1, &c, 1);
	return (res);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		len = check_error(len, ft_putstr("(null)"));
	else
	{
		while (*s != '\0')
		{
			len = check_error(len, ft_putchar(*s));
			s++;
		}
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len = check_error(len, ft_putstr("-2147483648"));
	}
	else
	{
		if (n < 0)
		{
			len = check_error(len, ft_putchar('-'));
			n = -1 * n;
		}
		if (n >= 10)
		{
			len = check_error(len, ft_putnbr(n / 10));
			len = check_error(len, ft_putchar(n % 10 + 48));
		}
		else
		{
			len = check_error(len, ft_putchar(n + 48));
		}
	}
	return (len);
}
