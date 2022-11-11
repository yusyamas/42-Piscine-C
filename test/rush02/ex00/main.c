/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: skotone <skotone@student.42tokyo.jp>       +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/10/23 08:00:33 by skotone           #+#    #+#             */
/*   Updated: 2022/10/23 08:00:33 by skotone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putvalue(char *str);
void	ft_put_one(char c, char *dict);
void	ft_put_two(char c, char *dict);
void	ft_put_teen(char *c, char *dict);
void	put_num_small(char *argv, char *dict, int num_mod);
char	*to_string(int num);
char	*int_to_value(int num, char *dict);

char	*put_digit(int num_digit)
{
	char	*char_digit;
	int		i;

	i = 1;
	char_digit = malloc(40 * sizeof(char));
	char_digit[0] = '1';
	num_digit *= 3;
	if (num_digit == 0)
		return (0);
	while (num_digit > 0)
	{
		char_digit[i] = '0';
		i++;
		num_digit--;
	}
	char_digit[i] = ':';
	char_digit[i + 1] = '\0';
	printf("%s ", char_digit);
	return (char_digit);
}

void	put_num_all(char *argv, char *dict)
{
	int	num_len;
	int	num_digit;
	int	mod;

	num_len = ft_strlen(argv);
	num_digit = (num_len - 1) / 3;
	mod = num_len % 3;
	if (num_len == 1 && argv[0] == '0')
	{
		ft_putstr(int_to_value(0, dict));
		return ;
	}
	put_num_small(argv, dict, mod);
	put_digit(num_digit);
	argv += mod;
	num_digit--;
	while (num_digit >= 0)
	{
		put_num_small(argv, dict, 0);
		put_digit(num_digit);
		argv += 3;
		num_digit--;
	}
}

int	main(int argc, char **argv)
{
	char	*dict;

	if (argc <= 1 || argc >= 4)
		error_msg(3);
	else if (argc == 2 && is_valid_num(argv[1]))
	{
		dict = input_dict("./numbers.dict");
		put_num_all(argv[1], dict);
	}
	else if (argc == 3 && is_valid_num(argv[2]))
	{
		dict = input_dict("./numbers.dict");
		put_num_all(argv[2], dict);
	}
	ft_putchar('\n');
	return (0);
}
