/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:53:27 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:36 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_lstlen(t_list *lst)
{
	size_t		len;

	len = 0;
	if (!lst)
		return (len);
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
