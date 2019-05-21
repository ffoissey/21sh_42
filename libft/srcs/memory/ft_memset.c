/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 00:02:39 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:42 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	if (!len)
		return (b);
	*((unsigned char *)b) = (unsigned char)c;
	while (--len > 0)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}
