/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:25:20 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/09 12:37:52 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

int	x10_overflow_check(int num)
{
	if (num <= INT_MAX / 10)
		return (0);
	return (1);
}

int	plus_overflow_check(int num, int x)
{
	if (num <= INT_MAX - x)
		return (0);
	return (1);
}

int	c_rush_00_atoi(char *c)
{
	int	sum;
	int	digit_number;

	sum = 0;
	while (*c != FT_NULL)
	{
		if (*c < '0' || *c > '9')
			return (-1);
		if (x10_overflow_check(sum))
			return (-1);
		sum *= 10;
		digit_number = *c - '0';
		if (plus_overflow_check(sum, digit_number))
			return (-1);
		sum += digit_number;
		c += 1;
	}
	return (sum);
}

int	print_error(int x, int y)
{
	if (x < 0 || y < 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (x == 0 || y == 0)
	{
		write(2, "Warning XorY=0\n", 15);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	if (argc == 3)
	{
		x = c_rush_00_atoi(argv[1]);
		y = c_rush_00_atoi(argv[2]);
	}
	if (print_error(x, y))
		return (1);
	return (rush(x, y));
}
