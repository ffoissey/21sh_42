/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:07:09 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:41 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_malloc.h"
#include <stdlib.h>

static void	ft_init(void *s, size_t n)
{
	if (!n)
		return ;
	*((char *)s) = 0;
	while (--n > 0)
		((char *)s)[n] = '\0';
}

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!size || !(ptr = ft_malloc(size)))
		return (NULL);
	ft_init(ptr, size);
	return (ptr);
}
