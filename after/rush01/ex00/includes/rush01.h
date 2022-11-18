/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:39:37 by yusyamas          #+#    #+#             */
/*   Updated: 2022/11/18 00:14:29 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int	n;
	int	factn;
	int	*rule;
	int	**grid;
	int	**npcontainer;
	int	*dfscursor;
}		t_data;

int		print_error(void);
int		grid_size_check(char *str);
void	data_init(t_data *data);
int		input_rule(t_data *data, char *str);
void	np_init(t_data *data);
int		grid_decision_dfs(t_data *data, int depth);
void	data_free(t_data *data);
void	print_grid(t_data *data);

int		check_building_puzzle(t_data *data);

int		my_strlen(char *str);
int		my_factorial(int nb);
void	my_iota(int *sample, int n);

#endif
