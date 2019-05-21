/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:58:16 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:32 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	ft_process_free(t_list **lst, void *ptr)
{
	t_list		*tmp;
	t_list		*run;

	if ((*lst)->data == ptr)
	{
		tmp = (*lst)->next;
		free(ptr);
		free(*lst);
		*lst = tmp;
		return ;
	}
	run = *lst;
	tmp = run;
	while (run != NULL)
	{
		if (run->data == ptr)
		{
			free(ptr);
			tmp->next = tmp->next->next;
			free(run);
			return ;
		}
		tmp = run;
		run = run->next;
	}
}

void		ft_free(void *ptr)
{
	t_list		*lst;
	t_list		*head;

	head = ft_get_head_list_allocation(GET_HEAD);
	lst = head->data;
	if (lst == NULL || ptr == NULL)
		return ;
	else
		ft_process_free(&lst, ptr);
	head->data = lst;
}
