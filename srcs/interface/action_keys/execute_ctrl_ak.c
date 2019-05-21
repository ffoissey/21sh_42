/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ctrl_ak.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 07:30:12 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:55 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_functions.h"
#include <termcap.h>

int8_t		tc_ak_ctrl_d(t_registry *shell)
{
	if (shell->interface.line->buffer[0] == '\0')
	{
		shell->interface.line->buffer[0] = 4;
		shell->interface.line->buffer[1] = '\0';
	}
	else
		tc_ak_delete(shell);
	return (SUCCESS);
}

int8_t		tc_ak_clear_screen(t_registry *shell)
{
	size_t initial_cursor_pos;

	if (validate_interface_content(&shell->interface) == FAILURE)
		return (FAILURE);
	initial_cursor_pos = shell->interface.cursor.index;
	tc_ak_end(shell);
	tputs(shell->interface.termcaps.clear, shell->interface.window.rows,
					ft_putc);
	redraw_prompt(ft_atoi(INT_MAGIC_NUMBER));
	shell->interface.cursor.index = redraw_input_line(shell);
	while (shell->interface.cursor.index < initial_cursor_pos)
		tc_ak_arrow_right(shell);
	return (SUCCESS);
}
