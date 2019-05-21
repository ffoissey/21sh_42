/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:32:40 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:50 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strspn(const char *s, const char *charset)
{
	int			i;

	i = 0;
	while (*s)
	{
		if (ft_strchr(charset, *s) == NULL)
			return (i);
		s++;
		i++;
	}
	return (i);
}
