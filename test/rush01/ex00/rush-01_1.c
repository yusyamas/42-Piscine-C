/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:10:42 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/16 00:48:07 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *x, int i, int j)
{
	int	tmp;

	tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		ft_swap(tab, i, j);
		i += 1;
		j -= 1;
	}
}

int	my_next_permutation(int *array, int num)
{
	int	i;
	int	j;

	i = num - 1;
	while (array[i - 1] >= array[i])
	{
		if (--i == 0)
		{
			return (0);
		}
	}
	j = num - 1;
	while (j > i && array[j] <= array[i - 1])
	{
		j -= 1;
	}
	ft_swap(array, i - 1, j);
	ft_rev_int_tab(array + i, num - i);
	return (1);
}
