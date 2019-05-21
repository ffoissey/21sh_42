/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_getdata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:54:44 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:33 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

void	*ft_hmap_getdata(t_hash *hashmap, char *key)
{
	uint32_t	hash;
	t_list		*ptr;
	t_hnode		*node;

	hash = ft_hash_str(key, hashmap->map_size);
	if (!(ptr = hashmap->map[hash]))
		return (0);
	while (ptr != NULL)
	{
		node = ((t_hnode *)ptr->data);
		if (!ft_strcmp(node->key, key))
			return (node->data);
		ptr = ptr->next;
	}
	return (0);
}
