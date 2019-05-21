/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:58:06 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:33 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	ft_replace_node(t_list **lst_ptr, void *old_ptr
						, unsigned char **new)
{
	t_list		*run;

	run = *lst_ptr;
	while (run != NULL)
	{
		if (run->data == old_ptr)
		{
			free(old_ptr);
			run->data = *new;
			return ;
		}
		run = run->next;
	}
	ft_lstadd(lst_ptr, ft_lstnew_no_malloc(new));
}

void		*ft_realloc(void *old_ptr, size_t size)
{
	t_list				*head;
	t_list				*lst_ptr;
	unsigned char		*new;

	if (size == 0)
		return (NULL);
	head = ft_get_head_list_allocation(GET_HEAD);
	lst_ptr = head->data;
	new = malloc(size);
	if (old_ptr == NULL || lst_ptr == NULL)
		ft_lstadd(&lst_ptr, ft_lstnew_no_malloc(&new));
	else
		ft_replace_node(&lst_ptr, old_ptr, &new);
	head->data = lst_ptr;
	return (new);
}
