/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:19:49 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:01:36 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "interface_functions.h"
#include "lexer.h"
#include "sig.h"
#include <unistd.h>

int8_t		shell_usage(void)
{
	ft_dprintf(2, "%s%s\nLong options:%s%s",
					SH21_USAGE_1,
					SH21_USAGE_2,
					SH21_USAGE_LONG_OPTION,
					SH21_USAGE_LONG_OPTION_2);
	return (FAILURE);
}

static int	stdin_build_cmd(t_registry *shell, char *command)
{
	execution_pipeline(shell, lexer(&shell->lexinfo, command));
	return (SUCCESS);
}

static void	batch_mode(t_registry *shell)
{
	char	*command;

	shell->is_interactive = FALSE;
	command = ((shell->option.option & COMMAND_OPT) != FALSE
			? shell->option.command_str : read_input(STDIN_FILENO));
	if (ft_strcheck(command, ft_isprint) == FALSE)
	{
		shell->option.command_str = NULL;
		ft_strdel(&command);
	}
	if (command != NULL && quoting_is_valid(command) == TRUE)
	{
		if (stdin_build_cmd(shell, command) == FAILURE)
			ft_dprintf(2, "[CRITICAL] - Malloc error.\n");
	}
	else
		ft_dprintf(2, "21sh: No valid input.\n");
	if ((shell->option.option & COMMAND_OPT) == FALSE && command != NULL)
		ft_strdel(&command);
}

static void	launch_shell(t_registry *shell)
{
	if ((shell->option.option & COMMAND_OPT) == FALSE
			&& isatty(STDIN_FILENO) != 0)
	{
		shell->is_interactive = TRUE;
		if ((load_interface(shell)) == SUCCESS)
			launch_interface(shell);
		else
			ft_dprintf(2, "[CRITICAL] - Interface setup failed. See logs.\n");
		unload_interface(&shell->interface);
	}
	else
		batch_mode(shell);
}

int			main(int ac, char **av, char **env)
{
	t_registry		shell;

	(void)ac;
	ft_bzero(&shell, sizeof(t_registry));
	g_shell = &shell;
	if (set_environment(&shell, av + 1, env) == FAILURE)
		return (FAILURE);
	if (init_shell(&shell) == FAILURE)
		return (FAILURE);
	define_ign_signals();
	launch_shell(&shell);
	shell_exit_routine(&shell);
	ft_flush_memory();
	return (SUCCESS);
}
