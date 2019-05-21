/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_clipboard_cut_ak.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:41:35 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:55 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_functions.h"
#include "log.h"

static int8_t		cut_vector(t_vector *vect, t_cursor *cursor,
							const int8_t before)
{
	char	*tmp;
	char	*foobar;

	tmp = ft_strnew(vect->size);
	if (before > 0)
	{
		foobar = ft_strsub(vect->buffer, cursor->index, ft_vctlen(vect));
		tmp = ft_strcpy(tmp, foobar);
		ft_strdel(&foobar);
	}
	else
		tmp = ft_strncpy(tmp, vect->buffer, cursor->index);
	ft_strdel(&(vect->buffer));
	vect->buffer = tmp;
	return (SUCCESS);
}

static void			copy_buffer_part(t_interface *itf, const int8_t before)
{
	char	*tmp;

	if (before > 0)
	{
		itf->clip->buffer = ft_strncpy(itf->clip->buffer, itf->line->buffer,
						itf->cursor.index);
		cut_vector(itf->line, &itf->cursor, before);
	}
	else
	{
		tmp = ft_strsub(itf->line->buffer, itf->cursor.index,
						ft_vctlen(itf->line));
		itf->clip->buffer = ft_strcpy(itf->clip->buffer, tmp);
		ft_strdel(&tmp);
		cut_vector(itf->line, &itf->cursor, before);
	}
}

int8_t				tc_ak_cut_before_cursor(t_registry *shell)
{
	t_interface	*itf;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	realloc_vector(itf->clip, itf->line);
	copy_buffer_part(itf, 1);
	log_print(shell, LOG_INFO, "Cut |%s| to clipboard.\n", itf->clip->buffer);
	redraw_input_line(shell);
	return (SUCCESS);
}

int8_t				tc_ak_cut_after_cursor(t_registry *shell)
{
	t_interface	*itf;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	realloc_vector(itf->clip, itf->line);
	copy_buffer_part(itf, -1);
	log_print(shell, LOG_INFO, "Cut |%s| to clipboard.\n", itf->clip->buffer);
	redraw_input_line(shell);
	return (SUCCESS);
}

int8_t				tc_ak_cut_line(t_registry *shell)
{
	t_interface	*itf;

	itf = &shell->interface;
	if (validate_interface_content(itf) == FAILURE)
		return (FAILURE);
	realloc_vector(itf->clip, itf->line);
	move_buffer(itf->clip->buffer, itf->line);
	log_print(shell, LOG_INFO, "Cut |%s| to clipboard.\n", itf->clip->buffer);
	redraw_input_line(shell);
	return (SUCCESS);
}
