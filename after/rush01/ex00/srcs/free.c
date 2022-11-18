/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:23:36 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/17 21:35:33 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	data_free_double(int **target, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(target[i]);
		i++;
	}
	free(target);
}

void	data_free(t_data *data)
{
	free(data->rule);
	free(data->dfscursor);
	data_free_double(data->grid, data->n);
	data_free_double(data->npcontainer, data->factn);
}
