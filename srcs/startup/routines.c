/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 07:18:22 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:06 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "parser.h"
#include "log.h"
#include "sig.h"
#include "lexer.h"
#include "resolve.h"
#include <unistd.h>

void		init_process(t_process *process)
{
	ft_bzero(process, sizeof(t_process));
}

int8_t		init_shell(t_registry *shell)
{
	g_shell = shell;
	shell->parse_signal = FALSE;
	init_debug_logger(shell);
	print_opt(shell);
	init_parsing(shell->parsing);
	generate_graph(shell);
	init_lexinfo(shell);
	return (SUCCESS);
}

void		init_parser(t_registry *shell, t_parser *parse)
{
	ft_stckinit(&parse->stack);
	parse->state = P_START;
	parse->env = shell->env;
	parse->oflags = 0;
	parse->valid = 0;
	init_process(&parse->process);
	ft_bzero(&parse->job, sizeof(t_job));
}

int8_t		execution_pipeline(t_registry *shell, t_list *token_list)
{
	t_parser	parse;

	shell->parse_signal = FALSE;
	define_parser_signals();
	ft_bzero(&parse, sizeof(t_parser));
	parse.token_list = token_list;
	parse.token.type = E_DEFAULT;
	lexer_print_debug(shell, parse.token_list);
	while (parse.token_list)
	{
		if (parser(shell->graph, parse.token_list) == FAILURE)
		{
			ft_lstdel(&parse.token_list, del_token);
			return (FAILURE);
		}
		init_parser(shell, &parse);
		shell->current_job = parser_state(shell->parsing, &parse);
		parser_print_debug(shell, &parse);
		lexer_print_debug(shell, parse.token_list);
		if (parse.valid == 1)
			launch_job(shell, parse.job_list);
		delete_parser(&parse);
	}
	define_ign_signals();
	return (SUCCESS);
}

void		shell_exit_routine(t_registry *shell)
{
	if ((shell->option.option & DEBUG_OPT) != FALSE)
		close(ft_atoi(get_intern_var(shell, INT_DBG_FD)));
	free_registry(shell);
}
