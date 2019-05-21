/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:00:13 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:47 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_malloc.h"

void	ft_strdel(char **as)
{
	if (!as || *as == NULL)
		return ;
	ft_free(*as);
	*as = NULL;
	return ;
}
