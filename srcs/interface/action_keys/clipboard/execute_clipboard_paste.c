/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_clipboard_paste.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:45:51 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:55 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "interface_functions.h"

static uint8_t		is_too_long(t_vector *a, t_vector *b, const uint32_t max)
{
	if (ft_vctlen(a) + ft_vctlen(b) >= max)
		return (TRUE);
	return (FALSE);
}

static uint32_t		insert_clipboard(t_registry *shell)
{
	t_interface		*itf;
	uint32_t		length;
	char			*after;
	char			*before;
	char			*concat;

	length = 0;
	concat = NULL;
	before = NULL;
	after = NULL;
	itf = &shell->interface;
	before = ft_strsub(itf->line->buffer, 0, itf->cursor.index);
	after = ft_strsub(itf->line->buffer, itf->cursor.index,
					ft_vctlen(itf->line));
	ft_asprintf(&concat, "%s%s%s", before, itf->clip->buffer, after);
	ft_bzero(itf->line->buffer, itf->line->size);
	ft_strncpy(itf->line->buffer, concat, ft_strlen(concat));
	length = ft_strlen(before) + ft_strlen(itf->clip->buffer);
	log_print(shell, LOG_INFO, "Inserting |%s| to line from clipboard.\n",
					itf->clip->buffer);
	ft_strdel(&concat);
	ft_strdel(&after);
	ft_strdel(&before);
	return (length);
}

static void			append_clipboard(t_registry *shell)
{
	t_interface *itf;

	itf = &shell->interface;
	itf->line->buffer = ft_strcat(itf->line->buffer,
			itf->clip->buffer);
	redraw_after_cursor(shell);
	tc_ak_end(shell);
	log_print(shell, LOG_INFO, "Appending |%s| to line from clipboard.\n",
					itf->clip->buffer);
}

int8_t				tc_ak_paste_clipboard(t_registry *shell)
{
	t_interface			*itf;
	uint32_t			go_front;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	if (is_too_long(itf->line, itf->clip, itf->window.max_chars) == TRUE)
		return (FAILURE);
	while (itf->line->size < (ft_vctlen(itf->line) + ft_vctlen(itf->clip) + 2))
		ft_vctrescale(itf->line);
	if (itf->line->buffer[itf->cursor.index] != '\0')
	{
		go_front = insert_clipboard(shell);
		tc_ak_home(shell);
		redraw_after_cursor(shell);
		while (go_front-- > 0)
			tc_ak_arrow_right(shell);
	}
	else
		append_clipboard(shell);
	return (SUCCESS);
}
