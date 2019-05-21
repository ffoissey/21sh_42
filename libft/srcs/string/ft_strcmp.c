/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:30:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:46 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	return (*s1 != *s2 || (!*s1 && !*s2) ?
			*(unsigned char *)s1 - *(unsigned char *)s2 :
			ft_strcmp(s1 + 1, s2 + 1));
}
