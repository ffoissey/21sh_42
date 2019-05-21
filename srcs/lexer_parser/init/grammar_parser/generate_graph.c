/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:42:01 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:00 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		generate_grammar(t_registry *shell)
{
	static const char	*grammar[] = { N_DB_QUOTE, N_PIPE,
			N_PARENT_OPEN, N_PARENT_CLOSE, N_GREAT, N_LESS, N_SEMICOLON,
			N_BACKQUOTE, N_AND, N_HOOK_OPEN, N_HOOK_CLOSE, N_BRACKET_OPEN,
			N_BRACKET_CLOSE, N_HASH, N_PERCENT, N_NEWLINE, N_DAND, N_OR,
			N_DSEMI, N_DLESS, N_DGREAT, N_LESSAND, N_GREATAND, N_LESSGREAT,
			N_ANDDGREAT, N_ANDGREAT, N_DLESSDASH, N_CLOBBER, N_DEQ,
			N_NOTEQ, N_CASE, N_DO, N_DONE, N_ELIF, N_ELSE, N_ESAC, N_FI, N_FOR,
			N_IF, N_IN, N_THEN, N_UNTIL, N_WHILE, N_IO_NUMBER, N_ASSIGN,
			N_STRING, N_SPSTRING, N_END, N_ERROR, N_START};

	shell->grammar = grammar;
}

void			generate_graph(t_registry *shell)
{
	generate_grammar(shell);
	set_start_token(shell->graph);
	set_word_token(shell->graph);
	set_redirect_token(shell->graph);
	set_assign_token(shell->graph);
	set_pipe_token(shell->graph);
	set_ionumber_token(shell->graph);
}
