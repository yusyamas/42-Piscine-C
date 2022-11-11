/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skotone <skotone@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 09:08:01 by skotone           #+#    #+#             */
/*   Updated: 2022/10/23 09:08:01 by skotone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void					ft_putchar(char c);
void					ft_putstr(char *str);
void					error_msg(int err_no);

unsigned long long int	unsigned_int_cal(char *str)
{
	unsigned long long int	num;
	int						i;

	i = 0;
	num = (str[i] - '0');
	i = 1;
	while (str[i] != '\0')
	{
		num *= 10;
		num += str[i] - '0';
		i ++;
	}
	return (num);
}

int	is_valid_num(char *argv)
{
	int						i;
	unsigned long long int	num;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] < '0' || argv[i] > '9')
		{
			error_msg(3);
			return (0);
		}
		i ++;
	}
	num = unsigned_int_cal(argv);
	if (num <= 4294967295)
		return (1);
	return (0);
}

char	*input_dict(char *filename)
{
	int		i;
	int		fd;
	int		r;
	char	*dict_tmp;
	char	*dict;

	i = 0;
	dict_tmp = malloc(3000 * sizeof(char));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error_msg(4);
		return (0);
	}
	r = read(fd, dict_tmp, 3000);
	dict = malloc((r + 1) * sizeof(char));
	while (i < r)
	{
		dict[i] = dict_tmp[i];
		i ++;
	}
	dict[i] = '\0';
	free(dict_tmp);
	close(fd);
	return (dict);
}
