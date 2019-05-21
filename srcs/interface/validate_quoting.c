/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_quoting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:54:16 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:59 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_functions.h"

static int64_t	goto_next_quote(const char *string,
									const char quote, uint32_t index)
{
	uint32_t		found_match;

	found_match = index;
	while (string[found_match] != '\0' && string[found_match] != quote)
		++found_match;
	if (string[found_match] == quote)
		return (found_match);
	return (FAILURE);
}

int8_t			quoting_is_valid(char *str)
{
	uint32_t	length;
	uint32_t	index;
	char		quote;

	quote = 0;
	index = 0;
	length = ft_strlen(str);
	while (index < length && str[index] != '\0')
	{
		quote = set_quote(str[index]);
		if (quote != FALSE)
		{
			if (goto_next_quote(str, quote, index + 1) != FAILURE)
				index = goto_next_quote(str, quote, index + 1);
			else
				return (FALSE);
		}
		++index;
	}
	return (TRUE);
}

void			validate_input_quoting(t_registry *shell, t_interface *itf)
{
	char	*line;
	char	*tmp_line;
	char	*final_line;
	char	*save_state;

	save_state = itf->state;
	while (quoting_is_valid(itf->line->buffer) == FALSE)
	{
		final_line = NULL;
		tmp_line = ft_strdup(itf->line->buffer);
		if (invoke_sub_prompt(shell, &line, INT_PS2) == FAILURE)
		{
			ft_strdel(&(tmp_line));
			reset_vector(itf->line);
			break ;
		}
		ft_asprintf(&final_line, "%s%c%s", tmp_line, IFS_CHAR, line);
		ft_strdel(&line);
		ft_strdel(&tmp_line);
		itf->line->buffer = ft_strdup(final_line);
		itf->line->size = ft_strlen(itf->line->buffer);
		ft_strdel(&final_line);
	}
	itf->state = save_state;
}
