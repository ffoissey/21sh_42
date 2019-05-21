/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 04:38:26 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:47 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "ft_malloc.h"

char		*ft_strinsert(char **str, char c, size_t index)
{
	char		*tmp;
	char		*cpy;
	size_t		len;
	size_t		i;

	if (!str || !*str)
		return (NULL);
	i = 0;
	cpy = *str;
	len = ft_strlen(*str) + 2;
	if (!(tmp = (char *)ft_malloc(sizeof(char) * len)))
		return (NULL);
	while (--len)
	{
		if (i == index)
			tmp[i] = c;
		else
			tmp[i] = *cpy++;
		i++;
	}
	tmp[i] = '\0';
	ft_strdel(str);
	return (tmp);
}
