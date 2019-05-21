/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:52:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:35 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		ft_lstdelfirst(t_list **alst, void (*del)(void *))
{
	if (!alst || !*alst)
		return (-1);
	ft_lstdelone(alst, del);
	return (0);
}
