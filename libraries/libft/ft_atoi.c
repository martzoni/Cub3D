/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasoni <mmasoni@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:50:49 by mmasoni           #+#    #+#             */
/*   Updated: 2023/10/12 14:49:31 by mmasoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	minus;

	i = 0;
	nbr = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		minus *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr *= 10;
		nbr += (int) str[i] - 48;
		i++;
	}
	nbr *= minus;
	return (nbr);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	const char *num = "\n\n\n  -46";

// 	(void) argc;
// 	(void) argv;
// 	printf("%d\n", atoi(num));
// 	printf("%d\n", ft_atoi(num));
// 	return (0);
// }