/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:03:23 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/23 22:18:07 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strstr_match_check(char *a, char *b)
{
	while (1)
	{
		if (*b == '\0')
			return (1);
		if (*a != *b)
			return (0);
		a += 1;
		b += 1;
	}
}

char	*ft_strstr_row(char *str, char *to_find)
{
	char	*a;
	char	*b;
	int		is_first;

	b = to_find;
	is_first = 1;
	while (*str != '\0')
	{
		if (is_first == 0 && *str == '\n')
		{
			is_first = 1;
			str += 1;
			continue ;
		}
		a = str;
		if (is_first == 1 && ft_strstr_match_check(a, b))
			return (str);
		is_first = 0;
		b = to_find;
		str += 1;
	}
	return (NULL);
}

char	*ft_make_string(int size)
{
	char	*c;

	c = malloc(sizeof(char) * (size + 2));
	return (c);
}

void	ft_to_string(char *c, int num, int size)
{
	int	i;

	i = size - 1;
	c[size + 1] = '\0';
	c[size] = ':';
	while (num)
	{
		c[i] = (num % 10) + '0';
		i--;
		num /= 10;
	}
}

char	*to_string(int num)
{
	char	*c;
	int		cnt;
	int		num_sub;

	cnt = 0;
	num_sub = num;
	if (num == 0)
	{
		c = ft_make_string(1);
		c[0] = '0';
		c[1] = ':';
		c[2] = '\0';
		return (c);
	}
	while (num_sub)
	{
		cnt++;
		num_sub /= 10;
	}
	c = ft_make_string(cnt);
	ft_to_string(c, num, cnt);
	return (c);
}
