/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:08:03 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:35 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnext(t_list *current, void f(void *))
{
	t_list *next;

	next = current->next->next;
	ft_lstdelone(&current->next, f);
	current->next = next;
}
