/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 07:17:47 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:37 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_manager(int mask)
{
	static int	check = 0;
	int			holder;

	if (mask == 1)
		return (check = 1);
	else if (mask == 0)
	{
		holder = check;
		check = 0;
		return (holder);
	}
	return (check);
}

t_list		*ereaser(t_list *current, void *data, int (*test)(void *, void *),\
					void (*del)(void *))
{
	t_list		*tmp;

	if (!current)
		return (NULL);
	else if (test(current->data, data))
	{
		tmp = current->next;
		ft_lstdelone(&current, del);
		tmp = ereaser(tmp, data, test, del);
		return_manager(1);
		return (tmp);
	}
	else
	{
		current->next = ereaser(current->next, data, test, del);
		return (current);
	}
}

int			ft_lstremove_if(t_list **lst, void *data,\
							int (*tst)(void *, void *), void (*del)(void *))
{
	t_list		*tmp;

	if (!lst || !*lst || !tst)
		return (return_manager(0));
	if (tst((*lst)->data, data))
	{
		tmp = (*lst)->next;
		ft_lstdelone(lst, del);
		*lst = tmp;
		return_manager(1);
		return (ft_lstremove_if(lst, data, tst, del));
	}
	if ((*lst)->next)
		(*lst)->next = ereaser((*lst)->next, data, tst, del);
	return (return_manager(0));
}
