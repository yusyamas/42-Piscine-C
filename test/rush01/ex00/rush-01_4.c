/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:28:26 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/16 10:11:33 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_b_p_col_up(int grid[4][4], int *rule, int *check_flag)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	j = 0;
	while (j < 4)
	{
		i = 0;
		old = 0;
		cnt = 0;
		while (i < 4)
		{
			if (old < grid[i][j])
			{
				old = grid[i][j];
				cnt += 1;
			}
			i += 1;
		}
		if (rule[j] != cnt)
			*check_flag = 0;
		j += 1;
	}
}

void	check_b_p_col_down(int grid[4][4], int *rule, int *check_flag)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	j = 0;
	while (j < 4)
	{
		i = 4 - 1;
		old = 0;
		cnt = 0;
		while (i >= 0)
		{
			if (old < grid[i][j])
			{
				old = grid[i][j];
				cnt += 1;
			}
			i -= 1;
		}
		if (rule[j + 4] != cnt)
			*check_flag = 0;
		j += 1;
	}
}

void	check_b_p_row_left(int grid[4][4], int *rule, int *check_flag)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	i = 0;
	while (i < 4)
	{
		j = 0;
		old = 0;
		cnt = 0;
		while (j < 4)
		{
			if (old < grid[i][j])
			{
				old = grid[i][j];
				cnt += 1;
			}
			j += 1;
		}
		if (rule[i + 4 * 2] != cnt)
			*check_flag = 0;
		i += 1;
	}
}

void	check_b_p_row_right(int grid[4][4], int *rule, int *check_flag)
{
	int	i;
	int	j;
	int	old;
	int	cnt;

	i = 0;
	while (i < 4)
	{
		j = 4 - 1;
		old = 0;
		cnt = 0;
		while (j >= 0)
		{
			if (old < grid[i][j])
			{
				old = grid[i][j];
				cnt += 1;
			}
			j -= 1;
		}
		if (rule[i + 4 * 3] != cnt)
			*check_flag = 0;
		i += 1;
	}
}

void	check_building_puzzle(int grid[4][4], int *rule, int *check_flag)
{
	check_b_p_col_up(grid, rule, check_flag);
	check_b_p_col_down(grid, rule, check_flag);
	check_b_p_row_left(grid, rule, check_flag);
	check_b_p_row_right(grid, rule, check_flag);
}
