/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 21:57:33 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:37 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include "ft_malloc.h"

char	**ft_lsttotab(t_list *lst, char *(*f)(void *))
{
	char	**result;
	size_t	lstlen;
	size_t	index;

	lstlen = ft_lstlen(lst);
	result = ft_malloc(sizeof(char *) * (lstlen + 1));
	index = 0;
	while (index < lstlen)
	{
		result[index++] = f(lst->data);
		lst = lst->next;
	}
	result[index] = NULL;
	return (result);
}
