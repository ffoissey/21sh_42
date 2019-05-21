/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:29:42 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:51 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_malloc.h"

t_vector	*ft_vctnew(size_t optional_size)
{
	t_vector	*new;
	char		*buffer;

	if (!(new = ft_malloc(sizeof(t_vector))))
		return (NULL);
	if (optional_size > 0)
	{
		if (!(buffer = ft_strnew(optional_size)))
		{
			ft_free(new);
			return (NULL);
		}
		new->size = optional_size;
	}
	else
	{
		if (!(buffer = ft_strnew(VECTOR_BUFFER_SIZE)))
		{
			ft_free(new);
			return (NULL);
		}
		new->size = VECTOR_BUFFER_SIZE;
	}
	new->buffer = buffer;
	return (new);
}
