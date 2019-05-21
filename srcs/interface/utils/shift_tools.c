/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:57:01 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:59 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strshift(char *str, ssize_t index, const int shift)
{
	ssize_t last;

	last = ft_strlen(str);
	if (shift == 0)
		return ;
	if (shift > 0)
	{
		while (last >= 0 && last >= index)
		{
			str[last + 1] = str[last];
			--last;
		}
	}
	else
	{
		while (index < last)
		{
			str[index] = str[index + 1];
			++index;
		}
		str[index] = '\0';
	}
}

void		shift_content_right_once(t_vector *vector, const uint32_t idx)
{
	if (idx >= (vector->size - 2)
					|| ft_strlen(vector->buffer) >= vector->size - 2)
		ft_vctrescale(vector);
	ft_strshift(vector->buffer, idx, 1);
}

void		shift_content_left_once(t_vector *vector, const uint32_t idx)
{
	ft_strshift(vector->buffer, idx, -1);
}
