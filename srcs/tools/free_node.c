/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:23:48 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:06 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void			clear_node(void **data)
{
	t_variable	*ptr;

	ptr = *data;
	ft_free(ptr->name);
	ft_free(ptr->data);
}

void			free_anode(t_list *ptr)
{
	clear_node(&ptr->data);
	ft_free(ptr->data);
}

int8_t			del_node(t_list *ptr, const char *name)
{
	t_list	*tmp;

	tmp = ptr;
	ptr = ptr->next;
	while (ptr != NULL)
	{
		if (ft_strequ(((t_variable *)ptr->data)->name, name) == TRUE)
		{
			tmp->next = ptr->next;
			free_anode(ptr);
			ft_free(ptr);
			return (SUCCESS);
		}
		tmp = tmp->next;
		ptr = ptr->next;
	}
	return (FAILURE);
}

int8_t			free_node(t_list **alst, const char *name)
{
	t_list		*ptr;
	t_variable	*env;

	ptr = *alst;
	env = (t_variable*)ptr->data;
	if (ft_strequ(env->name, name) == TRUE)
	{
		*alst = ptr->next;
		free_anode(ptr);
		ft_free(ptr);
		return (SUCCESS);
	}
	return (del_node(ptr, name));
}

void			free_one_node_token(t_list **token_lst)
{
	t_token	*token;

	token = (t_token *)((*token_lst)->data);
	ft_strdel(&token->data);
	ft_free(token);
	ft_free(*token_lst);
	*token_lst = NULL;
}
