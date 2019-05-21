/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 11:38:46 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:59 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "interface_functions.h"
#include "sh21.h"
#include <unistd.h>
#include <sys/ioctl.h>

int8_t	update_window(t_registry *shell)
{
	struct winsize	w;
	t_window		*window;

	window = &shell->interface.window;
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w) == FAILURE)
		return (FAILURE);
	window->rows = (w.ws_row <= 0) ? 0 : w.ws_row;
	window->cols = (w.ws_col <= 0) ? 0 : w.ws_col;
	if (add_internal_nbr(shell, INT_COLS, window->cols) == FAILURE)
		return (FAILURE);
	if (add_internal_nbr(shell, INT_ROWS, window->rows) == FAILURE)
		return (FAILURE);
	window->max_chars = ((window->cols * window->rows)
								- (get_prompt_len(shell) + 3));
	return (SUCCESS);
}

int8_t	init_window(t_registry *shell)
{
	struct winsize	w;
	t_window		*window;

	window = &shell->interface.window;
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w) == FAILURE)
	{
		log_print(shell, LOG_ERROR, "Terminal size could not be determined!\n");
		return (FAILURE);
	}
	window->rows = (w.ws_row <= 0) ? 0 : w.ws_row;
	window->cols = (w.ws_col <= 0) ? 0 : w.ws_col;
	if (add_internal_nbr(shell, INT_COLS, window->cols) == FAILURE)
		return (FAILURE);
	if (add_internal_nbr(shell, INT_ROWS, window->rows) == FAILURE)
		return (FAILURE);
	window->max_chars = ((window->cols * window->rows)
								- (get_prompt_len(shell) + 3));
	return (SUCCESS);
}

int8_t	init_cursor(t_registry *shell)
{
	t_cursor *cursor;

	cursor = &shell->interface.cursor;
	cursor->index = 0;
	cursor->x = get_prompt_len(shell);
	cursor->y = 0;
	return (SUCCESS);
}
