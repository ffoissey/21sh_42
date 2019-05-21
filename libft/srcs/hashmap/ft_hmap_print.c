/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:03:12 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:34 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

static void		print_map_info(t_hash *hashmap)
{
	size_t	fill;

	fill = ft_hmap_filled_norm(hashmap);
	if (fill < 20 || fill >= 70)
	{
		ft_printf("\n\x1b[31mMap size : %zu ", hashmap->map_size);
		ft_printf(" ||  . . . Printing . . .  || ");
		ft_printf(" Filled at %zu%%\x1b[0m\n\n", fill);
	}
	else
	{
		ft_printf("\n\x1b[32mMap size : %zu ", hashmap->map_size);
		ft_printf(" ||  . . . Printing . . .  || ");
		ft_printf(" Filled at %zu%%\x1b[0m\n\n", fill);
	}
}

void			ft_print_hashmap_p(t_hash *hashmap)
{
	size_t i;
	t_list *ptr;

	i = -1;
	print_map_info(hashmap);
	while (++i < hashmap->map_size)
	{
		if (hashmap->map[i] != NULL)
		{
			ft_printf("| %zu | :", i);
			ptr = hashmap->map[i];
			while (ptr != NULL)
			{
				ft_printf(" | Key = %s -> Data = %p | -"
				, ((t_hnode *)ptr->data)->key, ((t_hnode *)ptr->data)->data);
				ptr = ptr->next;
			}
			ft_printf(" NULL\n");
		}
	}
}

void			ft_print_hashmap(t_hash *hashmap)
{
	size_t		i;
	t_list		*ptr;

	i = -1;
	print_map_info(hashmap);
	while (++i < hashmap->map_size)
	{
		if (hashmap->map[i] != NULL)
		{
			ft_printf("| %zu | :", i);
			ptr = hashmap->map[i];
			while (ptr != NULL)
			{
				ft_printf(" | Key = %s -> Data = %s | -"
				, ((t_hnode*)ptr->data)->key, ((t_hnode*)ptr->data)->data);
				ptr = ptr->next;
			}
			ft_printf(" NULL\n");
		}
	}
}
