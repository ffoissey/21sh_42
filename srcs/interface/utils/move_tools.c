/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:26:46 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:58 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"

static int8_t	only_whitespaces_after(const char *str, const uint32_t index,
					const char direction)
{
	uint32_t idx;

	idx = index;
	if (direction > 0)
	{
		while (str[idx] != '\0' && str[idx] != ' ')
			++idx;
		while (str[idx] != '\0')
			if (str[idx++] != ' ')
				return (FALSE);
	}
	else
	{
		while (idx > 0 && str[idx] != ' ')
			--idx;
		while (idx > 0)
			if (str[idx--] != ' ')
				return (FALSE);
	}
	return (TRUE);
}

uint32_t		get_next_char(const char *str, uint32_t index,
					const char direction)
{
	if (only_whitespaces_after(str, index, direction) == TRUE)
		return (index);
	if (direction > 0)
	{
		while (str[index] != '\0' && str[index] != ' ')
			++index;
		while (str[index] != '\0' && str[index] == ' ')
			++index;
	}
	else
	{
		while (index > 0 && str[index] != ' ')
			--index;
		while (index > 0 && str[index] == ' ')
			--index;
		while (index > 0 && str[index - 1] != ' ')
			--index;
	}
	return (index);
}
