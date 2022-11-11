/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:34:56 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/23 19:58:06 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

void					ft_putchar(char c);
void					ft_putstr(char *str);
int						ft_strlen(char *str);
void					error_msg(int err_no);
unsigned long long int	unsigned_int_cal(char *str);
int						is_valid_num(char *argv);
char					*input_dict(char *filename);

#endif
