/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_interface_config.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 23:53:07 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:57 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "interface_functions.h"
#include "sh21.h"
#include <termcap.h>

static int8_t		fill_interface_data(t_registry *shell)
{
	if ((shell->interface.line = ft_vctnew(0)) == NULL)
		return (FAILURE);
	shell->interface.state = INT_PS1;
	if (init_window(shell) == FAILURE)
		return (FAILURE);
	return (init_cursor(shell));
}

static int8_t		fetch_terminal_info(t_registry *shell)
{
	char			*term_name;

	if ((term_name = getenv("TERM")) == NULL || ft_strequ(term_name, ""))
	{
		term_name = INT_TERM_DFLT_VALUE;
		add_internal(shell, INT_TERM, INT_TERM_DFLT_VALUE);
	}
	else
		add_internal(shell, INT_TERM, term_name);
	if (term_name == NULL || (tgetent(NULL, term_name)) == FAILURE)
	{
		log_print(shell, LOG_ERROR, "Tgetent failed.\n");
		return (FAILURE);
	}
	log_print(shell, LOG_OK,
			"Reached targeting terminal and termcaps database.\n");
	return (SUCCESS);
}

int8_t				fill_interface_related_internals(t_registry *shell)
{
	get_prompt_ps1(shell);
	if (add_internal(shell, INT_PS2, INT_PS2_VALUE) == FAILURE)
		return (FAILURE);
	if (add_internal(shell, INT_PS3, INT_PS3_VALUE) == FAILURE)
		return (FAILURE);
	if (add_internal(shell, INT_PS4, INT_PS4_VALUE) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int8_t				load_interface(t_registry *shell)
{
	if (fetch_terminal_info(shell) == FAILURE)
		return (FAILURE);
	if ((init_termcap_calls(&shell->interface.termcaps)) == FAILURE)
		return (FAILURE);
	setup_keycodes(&shell->interface);
	link_actions_to_keys(shell->interface.tc_call);
	if (fill_interface_related_internals(shell) == FAILURE)
		return (FAILURE);
	if (set_term_behavior(shell) == FAILURE)
		return (FAILURE);
	if ((shell->interface.clip = allocate_clipboard(shell)) == NULL)
		return (FAILURE);
	shell->interface.history_head = NULL;
	shell->interface.hist_ptr = NULL;
	if (fill_interface_data(shell) == FAILURE)
		return (FAILURE);
	log_print(shell, LOG_OK, "Line edition initialized.\n");
	shell->interface.allow_input = TRUE;
	return (SUCCESS);
}
