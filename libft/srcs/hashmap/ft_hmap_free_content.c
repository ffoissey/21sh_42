/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_free_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:31:34 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:33 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"
#include "ft_malloc.h"

static void		free_hnode_lst(t_list **ptr, void (*del)(void *))
{
	t_list	*tmp;
	t_hnode	*node;

	while (*ptr != NULL)
	{
		tmp = *ptr;
		*ptr = (*ptr)->next;
		tmp->next = NULL;
		node = (t_hnode *)tmp->data;
		ft_del_hnode(node, del);
		ft_free(tmp);
	}
}

void			ft_hmap_free_content(t_hash *hashmap, void (*del)(void *))
{
	size_t	i;
	t_list	*ptr;

	i = 0;
	if (hashmap->used == 0)
		return ;
	while (i < hashmap->map_size)
	{
		ptr = hashmap->map[i];
		if (ptr)
		{
			free_hnode_lst(&ptr, del);
			hashmap->map[i] = NULL;
		}
		i++;
	}
	hashmap->used = 0;
}
