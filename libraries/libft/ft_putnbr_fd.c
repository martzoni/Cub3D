/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:03:04 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/16 16:24:05 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -1 * n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + 48, fd);
		}
		else
		{
			ft_putchar_fd(n + 48, fd);
		}
	}
}

// int main ()
// { 
// 	int	nb = -2147483648;

// 	ft_putnbr_fd(nb, 1);
// 	return(0);
// }