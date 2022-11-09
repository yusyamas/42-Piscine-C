/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miida <miida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:29:23 by mogawa            #+#    #+#             */
/*   Updated: 2022/10/09 23:03:43 by miida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define T_L '/'
#define T_R '\\'
#define B_L '\\'
#define B_R '/'
#define HORIZ '*'
#define VERT '*'
#define SP ' '
#define EOL '\n'

void	ft_putchar(char c);

void	put_sign(int xx, int yy, int x, int y)
{
	if (xx == 0 && yy == 0)
		ft_putchar(T_L);
	else if (xx == x - 1 && yy == 0)
		ft_putchar(T_R);
	else if (xx == 0 && yy == y - 1)
		ft_putchar(B_L);
	else if (xx == x - 1 && yy == y - 1)
		ft_putchar(B_R);
	else if (xx == 0 || xx == x - 1)
		ft_putchar(VERT);
	else if (xx == x)
		ft_putchar(EOL);
	else if (yy == 0 || yy == y - 1)
		ft_putchar(HORIZ);
	else
		ft_putchar(SP);
}

int	rush(int x, int y)
{
	int	xx;
	int	yy;

	if (x < 0 || y < 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (x == 0 || y == 0)
	{
		write(2, "Warning XorY=0\n", 15);
		return (1);
	}
	yy = 0;
	while (yy <= y - 1)
	{
		xx = 0;
		while (xx <= x)
		{
			put_sign(xx, yy, x, y);
			xx += 1;
		}
		yy += 1;
	}
	return (0);
}
