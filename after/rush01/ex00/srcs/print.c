/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:37:06 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/17 21:44:14 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	print_grid(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < data->n)
	{
		j = 0;
		while (j < data->n)
		{
			c = data->grid[i][j] + '0';
			write(1, &c, 1);
			if (j == data->n - 1)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			j++;
		}
		i++;
	}
	data_free(data);
}
