/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skotone <skotone@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 09:05:10 by skotone           #+#    #+#             */
/*   Updated: 2022/10/23 09:05:10 by skotone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str ++;
	}
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count ++;
		str ++;
	}
	return (count);
}

void	error_msg(int err_no)
{
	if (err_no == 1)
		ft_putstr("Too many arguments.\n");
	else if (err_no == 2)
		ft_putstr("Dict Error\n");
	else if (err_no == 3)
		ft_putstr("Not valid arguments.\n");
	else if (err_no == 4)
		ft_putstr("Error.\n");
	return ;
}
