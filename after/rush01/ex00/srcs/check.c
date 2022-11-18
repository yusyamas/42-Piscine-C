/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:28:26 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/17 22:32:27 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_b_p_col_up(t_data *data)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	j = 0;
	while (j < data->n)
	{
		i = 0;
		old = 0;
		cnt = 0;
		while (i < data->n)
		{
			if (old < data->grid[i][j])
			{
				old = data->grid[i][j];
				cnt++;
			}
			i++;
		}
		if (data->rule[j] != cnt)
			return (0);
		j++;
	}
	return (1);
}

int	check_b_p_col_down(t_data *data)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	j = 0;
	while (j < data->n)
	{
		i = data->n - 1;
		old = 0;
		cnt = 0;
		while (i >= 0)
		{
			if (old < data->grid[i][j])
			{
				old = data->grid[i][j];
				cnt++;
			}
			i--;
		}
		if (data->rule[j + data->n] != cnt)
			return (0);
		j++;
	}
	return (1);
}

int	check_b_p_row_left(t_data *data)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	i = 0;
	while (i < data->n)
	{
		j = 0;
		old = 0;
		cnt = 0;
		while (j < data->n)
		{
			if (old < data->grid[i][j])
			{
				old = data->grid[i][j];
				cnt++;
			}
			j++;
		}
		if (data->rule[i + data->n * 2] != cnt)
			return (0);
		i++;
	}
	return (1);
}

int	check_b_p_row_right(t_data *data)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	i = 0;
	while (i < data->n)
	{
		j = data->n - 1;
		old = 0;
		cnt = 0;
		while (j >= 0)
		{
			if (old < data->grid[i][j])
			{
				old = data->grid[i][j];
				cnt++;
			}
			j--;
		}
		if (data->rule[i + data->n * 3] != cnt)
			return (0);
		i++;
	}
	return (1);
}

int	check_building_puzzle(t_data *data)
{
	if (!check_b_p_col_up(data))
		return (0);
	if (!check_b_p_col_down(data))
		return (0);
	if (!check_b_p_row_left(data))
		return (0);
	if (!check_b_p_row_right(data))
		return (0);
	return (1);
}
