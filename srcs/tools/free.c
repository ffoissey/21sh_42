/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:23:48 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:06 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int8_t			free_lst(t_list **alst)
{
	t_list	*ptr;
	t_list	*tmp;

	tmp = NULL;
	ptr = *alst;
	while (ptr != NULL)
	{
		free_anode(ptr);
		tmp = ptr;
		ptr = ptr->next;
		ft_free(tmp);
	}
	*alst = NULL;
	return (SUCCESS);
}

void			free_token_list(t_list *token_list)
{
	if (token_list != NULL)
	{
		free_token_list(token_list->next);
		free_one_node_token(&token_list);
	}
}
