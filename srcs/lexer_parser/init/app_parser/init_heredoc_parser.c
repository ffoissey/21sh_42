/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:07:01 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:59 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_heredoc_delimiter(t_pstate parsing)
{
	parsing[P_HEREDOC_DELIMITER][E_STRING] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_SPSTRING] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_GREAT] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_GREATAND] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_LESS] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_LESSAND] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_DGREAT] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_ANDDGREAT] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_PIPE] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_SEMICOLON] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_NEWLINE] = heredoc_parser;
	parsing[P_HEREDOC_DELIMITER][E_END] = heredoc_parser;
}

void	init_heredoc_redirect(t_pstate parsing)
{
	parsing[P_IO_HEREDOC_REDIRECT][E_STRING] = heredoc_delimiter;
	parsing[P_IO_HEREDOC_REDIRECT][E_SPSTRING] = heredoc_delimiter;
	parsing[P_HEREDOC_REDIRECT][E_STRING] = heredoc_delimiter;
	parsing[P_HEREDOC_REDIRECT][E_SPSTRING] = heredoc_delimiter;
}

void	init_io_heredoc(t_pstate parsing)
{
	parsing[P_IO_HEREDOC][E_STRING] = string_parser;
	parsing[P_IO_HEREDOC][E_SPSTRING] = special_string_parser;
	parsing[P_IO_HEREDOC][E_GREAT] = redirect_parser;
	parsing[P_IO_HEREDOC][E_GREATAND] = redirect_parser;
	parsing[P_IO_HEREDOC][E_LESS] = redirect_parser;
	parsing[P_IO_HEREDOC][E_LESSAND] = redirect_parser;
	parsing[P_IO_HEREDOC][E_DGREAT] = redirect_parser;
	parsing[P_IO_HEREDOC][E_ANDDGREAT] = redirect_parser;
	parsing[P_IO_HEREDOC][E_PIPE] = flush_string;
	parsing[P_IO_HEREDOC][E_SEMICOLON] = flush_string;
	parsing[P_IO_HEREDOC][E_NEWLINE] = flush_string;
	parsing[P_IO_HEREDOC][E_END] = flush_string;
}

void	init_io_heredoc_delimiter(t_pstate parsing)
{
	parsing[P_IO_HEREDOC_DELIMITER][E_STRING] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_SPSTRING] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_GREAT] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_GREATAND] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_LESS] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_LESSAND] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_DGREAT] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_ANDDGREAT] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_PIPE] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_SEMICOLON] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_NEWLINE] = io_heredoc_parser;
	parsing[P_IO_HEREDOC_DELIMITER][E_END] = io_heredoc_parser;
}

void	init_heredoc(t_pstate parsing)
{
	parsing[P_HEREDOC][E_STRING] = string_parser;
	parsing[P_HEREDOC][E_SPSTRING] = special_string_parser;
	parsing[P_HEREDOC][E_GREAT] = redirect_parser;
	parsing[P_HEREDOC][E_GREATAND] = redirect_parser;
	parsing[P_HEREDOC][E_LESS] = redirect_parser;
	parsing[P_HEREDOC][E_LESSAND] = redirect_parser;
	parsing[P_HEREDOC][E_DGREAT] = redirect_parser;
	parsing[P_HEREDOC][E_ANDDGREAT] = redirect_parser;
	parsing[P_HEREDOC][E_PIPE] = flush_string;
	parsing[P_HEREDOC][E_SEMICOLON] = flush_string;
	parsing[P_HEREDOC][E_NEWLINE] = flush_string;
	parsing[P_HEREDOC][E_END] = flush_string;
}
