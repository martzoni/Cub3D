/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:51:54 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/26 14:32:28 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uputnbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len = check_error(len, ft_uputnbr(n / 10));
		len = check_error(len, ft_putchar(n % 10 + 48));
	}
	else
	{
		len = check_error(len, ft_putchar(n + 48));
	}
	return (len);
}

int	ft_puthexa(unsigned long int n, int x)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len = check_error(len, ft_puthexa(n / 16, x));
		if (n % 16 > 9)
			len = check_error(len, ft_putchar(n % 16 + x));
		else
			len = check_error(len, ft_putchar(n % 16 + 48));
	}
	else
	{
		if (n > 9)
			len = check_error(len, ft_putchar(n + x));
		else
			len = check_error(len, ft_putchar(n + 48));
	}
	return (len);
}

int	print_ptr(va_list args)
{
	void	*ptr;
	int		len;

	len = 0;
	ptr = va_arg(args, void *);
	len = check_error(len, ft_putstr("0x"));
	len = check_error(len, ft_puthexa((unsigned long int)ptr, 87));
	return (len);
}

int	check_arg(char c, va_list args)
{
	int		len;

	len = 0;
	if (c == 'c')
		len = check_error(len, ft_putchar(va_arg(args, int)));
	else if (c == 's')
		len = check_error(len, ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		len = check_error(len, print_ptr(args));
	else if (c == 'd')
		len = check_error(len, ft_putnbr(va_arg(args, int)));
	else if (c == 'i')
		len = check_error(len, ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		len = check_error(len, ft_uputnbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		len = check_error(len, ft_puthexa(va_arg(args, unsigned int), 87));
	else if (c == 'X')
		len = check_error(len, ft_puthexa(va_arg(args, unsigned int), 55));
	else if (c == '%')
		len = check_error(len, ft_putchar('%'));
	else if (c == '\0')
		return (-1);
	return (len);
}

int	ft_printf(const char *content, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, content);
	while (content[i] != '\0')
	{
		if (content[i] == '%' && check_next(content[i + 1], "cspdiuxX%") == 1)
		{
			i++;
			len = check_error(len, check_arg(content[i], args));
		}
		else
			len = check_error(len, ft_putchar(content[i]));
		i++;
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// char c = 'Q';
// 	// char *s = "SALUT";
// 	// int d = 176;
// 	// int i = 1234;
// 	printf("\n\nresultat 1: %i\n", printf("%c\n", 2456));

// 	ft_printf("\n\nresultat 2: %i\n", ft_printf("%c\n", 2456));

// 	return (0);
// }
