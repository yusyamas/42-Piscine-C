/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:00:32 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/17 22:11:12 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	grid_size_check(char *str)
{
	int	strlen;
	int	n;

	strlen = my_strlen(str);
	n = (strlen + 1) / 8;
	if (strlen != 8 * n - 1)
		return (-1);
	return (n);
}

int	input_rule(t_data *data, char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < 8 * data->n - 1)
	{
		if (i % 2 == 0)
		{
			if ('1' <= str[i] && str[i] <= (char)('0' + data->n))
			{
				data->rule[cnt] = str[i] - '0';
				cnt += 1;
			}
			else
				return (1);
		}
		else
		{
			if (str[i] != ' ')
				return (1);
		}
		i += 1;
	}
	return (0);
}
