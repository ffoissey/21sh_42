/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:43:27 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:37 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	*reversal(t_list *previous, t_list *current, t_list *next)
{
	if (current == NULL)
		return (previous);
	next = current->next;
	current->next = previous;
	previous = current;
	return (reversal(previous, next, NULL));
}

void			ft_lstrev(t_list **alst)
{
	*alst = reversal(NULL, *alst, NULL);
	return ;
}
