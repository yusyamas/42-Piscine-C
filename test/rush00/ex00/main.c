/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miida <miida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:25:20 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/09 23:03:47 by miida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define FT_NULL '\0'
#define INT_MAX 2147483647

void	ft_putchar(char c);

int		rush(int x, int y);

int	x10_overflow_check(int num)
{
	if (num <= INT_MAX / 10)
	{
		return (0);
	}
	return (1);
}

int	plus_overflow_check(int num, int x)
{
	if (num <= INT_MAX - x)
	{
		return (0);
	}
	return (1);
}

int	c_rush_00_atoi(char *c, int *is_error)
{
	int	sum;
	int	digit_number;

	sum = 0;
	while (*c != FT_NULL)
	{
		if (*c < '0' || *c > '9')
		{
			*is_error = 0;
			break ;
		}
		if (x10_overflow_check(sum))
		{
			*is_error = 0;
		}
		sum *= 10;
		digit_number = *c - '0';
		if (plus_overflow_check(sum, digit_number))
		{
			*is_error = 0;
		}
		sum += digit_number;
		c += 1;
	}
	return (sum);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;
	int	is_error;

	is_error = 1;
	if (argc >= 3)
	{
		x = c_rush_00_atoi(argv[1], &is_error);
		y = c_rush_00_atoi(argv[2], &is_error);
	}
	if (is_error == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	return (rush(x, y));
}
