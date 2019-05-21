/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:12:06 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:36 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	extract(t_list **h, t_list *c, void *ftr, int (*f)(void *, void *))
{
	t_list	*node;

	if (!c)
		return ;
	if (f(c->data, ftr))
	{
		node = ft_lstnew(c->data, c->data_size);
		ft_lstaddback(h, node);
	}
	return (extract(h, c->next, ftr, f));
}

t_list		*ft_lstfilter(t_list *lst, void *filter, int (*f)(void *, void *))
{
	t_list *new;

	new = NULL;
	if (f(lst->data, filter))
		new = ft_lstnew(lst->data, lst->data_size);
	extract(&new, lst->next, filter, f);
	return (new);
}
