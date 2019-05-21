/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:14:10 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:46 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strcspn(const char *s, const char *charset)
{
	int			i;
	const char	*c;

	i = 0;
	while (*s)
	{
		c = charset;
		while (*c)
		{
			if (*s == *c)
				return (i);
			c++;
		}
		s++;
		i++;
	}
	return (i);
}
