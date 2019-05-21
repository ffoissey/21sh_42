/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:11:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:41 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (!n)
		return (NULL);
	*(unsigned char *)dst = *(unsigned char *)src;
	if (*(unsigned char *)src == (unsigned char)c)
		return ((unsigned char *)dst + 1);
	return (n == 1 ? NULL : ft_memccpy(++dst, ++src, c, --n));
}
