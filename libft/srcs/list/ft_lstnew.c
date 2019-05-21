/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:11:51 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:37 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "ft_malloc.h"

t_list		*ft_lstnew(void const *data, size_t data_size)
{
	t_list		*new;

	if (!(new = (t_list *)ft_malloc(sizeof(t_list))))
		return (NULL);
	if (!data)
	{
		new->data = NULL;
		new->data_size = 0;
		new->next = NULL;
		return (new);
	}
	if (!(new->data = ft_malloc(data_size)))
	{
		ft_free(new);
		return (NULL);
	}
	new->data_size = data_size;
	ft_memcpy(new->data, data, data_size);
	new->next = NULL;
	return (new);
}
