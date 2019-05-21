/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:54:39 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:32 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_calloc(size_t size)
{
	void	*ptr;

	ptr = ft_malloc(size);
	ft_bzero(ptr, size);
	return (ptr);
}
