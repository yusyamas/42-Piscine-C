/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:44:54 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/18 11:43:59 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (print_error());
	data.n = grid_size_check(argv[1]);
	data_init(&data);
	if (data.n < 2 || data.n > 5 || input_rule(&data, argv[1]))
	{
		data_free(&data);
		return (print_error());
	}
	np_init(&data);
	if (grid_decision_dfs(&data, 0))
		print_grid(&data);
	else
	{
		data_free(&data);
		return (print_error());
	}
	return (0);
}
