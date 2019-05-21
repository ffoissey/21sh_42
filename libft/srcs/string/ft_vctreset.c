/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctreset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:47:34 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:51 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vctreset(t_vector *vct)
{
	char *new;

	if (!(new = ft_strnew(VECTOR_BUFFER_SIZE)))
		return (1);
	ft_strdel(&(vct->buffer));
	vct->buffer = new;
	vct->size = VECTOR_BUFFER_SIZE;
	return (0);
}
