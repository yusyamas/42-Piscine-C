/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:22:32 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/17 22:31:57 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**data_init_double(t_data *data, int num)
{
	int	**ret;
	int	i;

	ret = (int **)malloc(sizeof(int *) * (num));
	i = 0;
	while (i < num)
	{
		ret[i] = (int *)malloc(sizeof(int) * (data->n));
		i++;
	}
	return (ret);
}

void	data_init(t_data *data)
{
	data->rule = (int *)malloc(sizeof(int) * (4 * data->n));
	data->dfscursor = (int *)malloc(sizeof(int) * (data->n + 1));
	data->dfscursor[0] = -1;
	data->grid = data_init_double(data, data->n);
	data->factn = my_factorial(data->n);
	data->npcontainer = data_init_double(data, (data->factn + 1));
}
