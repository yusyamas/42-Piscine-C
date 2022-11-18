/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:44:54 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/17 21:44:33 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	my_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		length += 1;
		str += 1;
	}
	return (length);
}

int	my_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (1);
	return (nb * my_factorial(nb - 1));
}

void	my_iota(int *sample, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		sample[i] = i + 1;
		i++;
	}
}
