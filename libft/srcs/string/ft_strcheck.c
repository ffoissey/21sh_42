/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:44:46 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:46 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcheck(char *str, int (*f)(int))
{
	if (str == NULL)
		return (-1);
	while (*str)
	{
		if (f(*str) == 0)
			return (0);
		++str;
	}
	return (1);
}
