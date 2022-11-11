/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: skotone <skotone@student.42tokyo.jp>       +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/10/23 18:39:41 by skotone           #+#    #+#             */
/*   Updated: 2022/10/23 18:39:41 by skotone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*int_to_value(int num, char *dict);

void	ft_putvalue(char *str)
{
	while (*str != '\n' && *str != EOF)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar(' ');
}

void	ft_put_one(char c, char *dict)
{
	int	i;

	i = 0;
	while (dict[i] != '\0')
	{
		while (dict[i] != '\n')
		{
			if (dict[i] == c && dict[i + 1] == ':')
			{
				dict += 3 + i;
				ft_putvalue(dict);
				return ;
			}
			i++;
		}
		i++;
	}
}

void	ft_put_two(char c, char *dict)
{
	int	i;

	i = 0;
	while (dict[i] != '\0')
	{
		while (dict[i] != '\n')
		{
			if (dict[i] == c && dict[i + 1] == '0' && dict[i + 2] == ':')
			{
				dict += 4 + i;
				ft_putvalue(dict);
				return ;
			}
			i++;
		}
		i++;
	}
}

void	ft_put_teen(char *c, char *dict)
{
	int	i;

	i = 0;
	while (dict[i] != '\0')
	{
		while (dict[i] != '\n')
		{
			if (dict[i] == c[0] && dict[i + 1] == c[1] && dict[i + 2] == ':')
			{
				dict += 4 + i;
				ft_putvalue(dict);
				return ;
			}
			i++;
		}
		i++;
	}
}

void	put_num_small(char *argv, char *dict, int num_mod)
{
	if (num_mod == 0)
	{
		if (argv[0] != '0')
		{
			ft_put_one(*argv, dict);
			ft_putstr(int_to_value(100, dict));
			ft_putchar(' ');
		}
		num_mod = 2;
		argv++;
	}
	if (num_mod == 2)
	{
		if (*argv == '1')
		{
			ft_put_teen(argv, dict);
			return ;
		}
		else if (*argv >= '2' && *argv <= '9')
			ft_put_two(*argv, dict);
		num_mod--;
		argv++;
	}
	if ((num_mod == 1) && (argv[0] != '0'))
		ft_put_one(*argv, dict);
}
