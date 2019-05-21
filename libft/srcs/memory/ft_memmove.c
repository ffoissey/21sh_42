/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:55:32 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:42 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (n)
	{
		if ((unsigned long)dst < (unsigned long)src)
			return (ft_memcpy(dst, src, n));
		else
		{
			while (--n > 0)
				((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
			*(unsigned char *)dst = *(unsigned char *)src;
		}
	}
	return (dst);
}
