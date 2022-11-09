/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:59:46 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/16 20:20:44 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_array_all_1(int *array, int *check_flag)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (array[i] != 1)
			*check_flag = 0;
		i += 1;
	}
}

void	array_init_zero(int *grid, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		grid[i] = 0;
		i += 1;
	}
}

void	count_height_check_horiz(int grid[4][4], int *check_flag)
{
	int	i;
	int	j;
	int	count_height[4];

	i = 0;
	while (i < 4)
	{
		array_init_zero(count_height, 4);
		j = 0;
		while (j < 4)
		{
			count_height[grid[i][j] - 1] += 1;
			j += 1;
		}
		check_array_all_1(count_height, check_flag);
		i += 1;
	}
}

void	count_height_check_vert(int grid[4][4], int *check_flag)
{
	int	i;
	int	j;
	int	count_height[4];

	j = 0;
	while (j < 4)
	{
		array_init_zero(count_height, 4);
		i = 0;
		while (i < 4)
		{
			count_height[grid[i][j] - 1] += 1;
			i += 1;
		}
		check_array_all_1(count_height, check_flag);
		j += 1;
	}
}
