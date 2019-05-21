/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_clipboard_copy_ak.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:12:59 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:55 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "interface_functions.h"

int8_t	tc_ak_copy_before_cursor(t_registry *shell)
{
	t_interface	*itf;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	realloc_vector(itf->clip, itf->line);
	itf->clip->buffer = ft_strncpy(itf->clip->buffer,
					itf->line->buffer, itf->cursor.index);
	log_print(shell, LOG_INFO, "Copied |%s| to clipboard.\n",
					itf->clip->buffer);
	return (SUCCESS);
}

int8_t	tc_ak_copy_after_cursor(t_registry *shell)
{
	char		*tmp;
	t_interface	*itf;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	realloc_vector(itf->clip, itf->line);
	tmp = ft_strsub(itf->line->buffer,
			itf->cursor.index, ft_vctlen(itf->line));
	itf->clip->buffer = ft_strcpy(itf->clip->buffer, tmp);
	ft_strdel(&tmp);
	log_print(shell, LOG_INFO, "Copied |%s| to clipboard.\n",
					itf->clip->buffer);
	return (SUCCESS);
}

int8_t	tc_ak_copy_line(t_registry *shell)
{
	t_interface	*itf;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	realloc_vector(itf->clip, itf->line);
	ft_strcpy(itf->clip->buffer, itf->line->buffer);
	log_print(shell, LOG_INFO, "Copied |%s| to clipboard.\n",
					itf->clip->buffer);
	return (SUCCESS);
}
