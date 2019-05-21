/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:37:06 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:48 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "ft_malloc.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*map;
	char				*tmp;
	unsigned int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(map = (char *)ft_malloc(ft_strlen(s) + 1)))
		return (NULL);
	tmp = map;
	while (s[i])
	{
		*tmp++ = f(i, s[i]);
		i++;
	}
	*tmp = s[i];
	return (map);
}
