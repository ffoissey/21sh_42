/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckdestroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 21:26:01 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:37 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stckdestroy(t_stack *stack, void (*f)(void *))
{
	ft_lstdel(&stack->head, f);
	stack->size = 0;
}
