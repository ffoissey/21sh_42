/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:29:53 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:57 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "lexer.h"
#include "sig.h"
#include "history.h"
#include "sh21.h"
#include "interface_functions.h"
#include <termcap.h>

static void			update_history(t_registry *shell, char *input)
{
	t_history	*new;

	new = create_history_entry(input);
	push_history_entry(&shell->interface.history_head, new);
}

static int8_t		get_input(t_registry *shell, char **input)
{
	*input = prompt(shell);
	if (*input == NULL)
		return (FAILURE);
	else if (**input == '\0')
		return (get_input(shell, input));
	else if (is_eof(*input))
		return (FAIL_EOF);
	return (SUCCESS);
}

static int8_t		launch_shell_prompt(t_registry *shell)
{
	int8_t		completed;
	char		*input;

	define_interface_signals();
	completed = get_input(shell, &input);
	if (completed == FAILURE || completed == FAIL_EOF)
	{
		cleanup_interface(shell);
		if (completed == FAIL_EOF)
			return (FAILURE);
		if (get_input(shell, &input) == FAILURE)
		{
			ft_dprintf(2, "\n21sh: read() has failed 2 consecutive times.\n");
			ft_dprintf(2, "21sh: Shutting down.\n");
			return (FAILURE);
		}
	}
	ft_putchar('\n');
	update_history(shell, input);
	define_ign_signals();
	execution_pipeline(shell, lexer(&shell->lexinfo, input));
	return (SUCCESS);
}

/*
**	This is the main function to invoke the interactive
**  line edition, aside from logging its progress,
**	it iterates on the function launch_shell_prompt,
**	which displays the real prompt, send input to the execution pipeline,
**	and cleans it up on successfull completion.
**	On exit, we restore the previous terminal behavior (via. the Termios struct)
*/

void				launch_interface(t_registry *shell)
{
	log_print(shell, LOG_INFO, "Starting interface.\n");
	while (launch_shell_prompt(shell) == SUCCESS)
		cleanup_interface(shell);
	restore_term_behavior(shell);
}
