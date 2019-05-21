/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 23:13:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:29 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <limits.h>

static int		numlen(long long n)
{
	int		i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	void	converter(char *buffer, long long n, int i)
{
	if (n > 0)
	{
		converter(buffer, n / 10, --i);
		buffer[i] = n % 10 + '0';
	}
}

char			*ft_llitoa(long long n)
{
	int		flag;
	int		len;
	char	*buffer;

	if (n == 0)
		return (ft_strdup("0"));
	len = numlen(n);
	flag = n < 0 ? 1 : 0;
	buffer = ft_strnew(len + flag);
	if (flag)
		*buffer = '-';
	if (n == LONG_MIN)
	{
		n++;
		converter(buffer + flag, -n, len);
		buffer[19] += 1;
	}
	else
		converter(buffer + flag, flag == 0 ? (long)n : -(long)n, len);
	return (buffer);
}
