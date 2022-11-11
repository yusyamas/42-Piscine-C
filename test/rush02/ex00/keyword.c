/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:03:26 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/23 22:10:47 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*to_string(int num);

char	*ft_strstr_row(char *str, char *to_find);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	while (*s != '\0' && n)
	{
		*d = *s;
		d += 1;
		s += 1;
		n -= 1;
	}
	while (n)
	{
		*d = '\0';
		d += 1;
		n -= 1;
	}
	return (dest);
}

int	ft_strlen_key(char *c)
{
	int	len;

	len = 0;
	while (*c != '\n')
	{
		len += 1;
		c += 1;
	}
	return (len);
}

char	*ft_keyword_extract(char *c)
{
	int		len;
	char	*ret;

	while (*c != ' ')
		c += 1;
	c += 1;
	len = ft_strlen_key(c);
	ret = malloc(sizeof(char) * (len + 1));
	ft_strncpy(ret, c, len);
	ret[len] = '\0';
	return (ret);
}

char	*int_to_value(int num, char *dict)
{
	char	*tmp;

	tmp = to_string(num);
	tmp = ft_strstr_row(dict, tmp);
	tmp = ft_keyword_extract(tmp);
	return (tmp);
}
