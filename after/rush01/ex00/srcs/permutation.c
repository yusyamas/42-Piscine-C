/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:10:42 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/17 22:07:19 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	my_swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

void	my_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		my_swap(&tab[i], &tab[j]);
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
		i--;
		if (i == 0)
			return (0);
	}
	j = num - 1;
	while (j > i && array[j] <= array[i - 1])
		j--;
	my_swap(&array[i - 1], &array[j]);
	my_rev_int_tab(array + i, num - i);
	return (1);
}

void	array_copy(t_data *data, int i, int *sample)
{
	int	j;

	j = 0;
	while (j < data->n)
	{
		data->npcontainer[i][j] = sample[j];
		j++;
	}
}

void	np_init(t_data *data)
{
	int	*sample;
	int	i;

	sample = (int *)malloc(sizeof(int) * (data->n));
	my_iota(sample, data->n);
	i = 0;
	while (1)
	{
		array_copy(data, i, sample);
		if (my_next_permutation(sample, data->n) == 0)
			break ;
		i++;
	}
	free(sample);
}
