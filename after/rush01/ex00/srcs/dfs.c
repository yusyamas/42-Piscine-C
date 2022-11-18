/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:16:00 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/17 23:02:44 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_before_height(t_data *data, int per, int depth)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->n)
	{
		i = 0;
		while (i < depth)
		{
			if (data->grid[i][j] == data->npcontainer[per][j])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	array_decide(t_data *data, int per, int depth)
{
	int	j;

	if (!check_before_height(data, per, depth))
		return (0);
	j = 0;
	while (j < data->n)
	{
		data->grid[depth][j] = data->npcontainer[per][j];
		j++;
	}
	return (1);
}

int	grid_decision_dfs(t_data *data, int depth)
{
	int	i;

	if (depth == data->n)
		return (check_building_puzzle(data));
	i = 0;
	while (i < data->factn)
	{
		if (array_decide(data, i, depth))
		{
			data->dfscursor[depth + 1] = i;
			if (grid_decision_dfs(data, depth + 1))
				return (1);
		}
		i++;
	}
	return (0);
}
