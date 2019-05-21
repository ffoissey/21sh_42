/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_io_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:54:44 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:59 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_io(t_pstate parsing)
{
	parsing[P_IO][E_GREAT] = io_redirect_parser;
	parsing[P_IO][E_DGREAT] = io_redirect_parser;
	parsing[P_IO][E_LESS] = io_redirect_parser;
	parsing[P_IO][E_GREATAND] = io_redirect_and_parser;
	parsing[P_IO][E_LESSAND] = io_redirect_and_parser;
}

void	init_io_filename(t_pstate parsing)
{
	parsing[P_IO_FILENAME][E_STRING] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_SPSTRING] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_GREAT] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_GREATAND] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_LESS] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_LESSAND] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_DGREAT] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_ANDDGREAT] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_PIPE] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_IO_NUMBER] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_SEMICOLON] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_NEWLINE] = io_redirect_flush;
	parsing[P_IO_FILENAME][E_END] = io_redirect_flush;
}

void	init_io_filename_and(t_pstate parsing)
{
	parsing[P_IO_REDIRECT_AND][E_STRING] = io_dup_move_parser;
	parsing[P_IO_REDIRECT_AND][E_SPSTRING] = io_dup_move_parser;
}

void	init_io_flush(t_pstate parsing)
{
	parsing[P_IO_FLUSH][E_STRING] = string_parser;
	parsing[P_IO_FLUSH][E_SPSTRING] = special_string_parser;
	parsing[P_IO_FLUSH][E_GREAT] = redirect_parser;
	parsing[P_IO_FLUSH][E_GREATAND] = redirect_parser;
	parsing[P_IO_FLUSH][E_LESS] = redirect_parser;
	parsing[P_IO_FLUSH][E_LESSAND] = redirect_parser;
	parsing[P_IO_FLUSH][E_DGREAT] = redirect_parser;
	parsing[P_IO_FLUSH][E_ANDDGREAT] = redirect_parser;
	parsing[P_IO_FLUSH][E_IO_NUMBER] = io_parser;
	parsing[P_IO_FLUSH][E_PIPE] = flush_string;
	parsing[P_IO_FLUSH][E_SEMICOLON] = flush_string;
	parsing[P_IO_FLUSH][E_NEWLINE] = flush_string;
	parsing[P_IO_FLUSH][E_END] = flush_string;
}

void	init_io_flush_and(t_pstate parsing)
{
	parsing[P_IO_FLUSH_AND][E_STRING] = string_parser;
	parsing[P_IO_FLUSH_AND][E_SPSTRING] = special_string_parser;
	parsing[P_IO_FLUSH_AND][E_GREAT] = redirect_parser;
	parsing[P_IO_FLUSH_AND][E_GREATAND] = redirect_parser;
	parsing[P_IO_FLUSH_AND][E_LESS] = redirect_parser;
	parsing[P_IO_FLUSH_AND][E_LESSAND] = redirect_parser;
	parsing[P_IO_FLUSH_AND][E_DGREAT] = redirect_parser;
	parsing[P_IO_FLUSH_AND][E_ANDDGREAT] = redirect_parser;
	parsing[P_IO_FLUSH_AND][E_IO_NUMBER] = io_parser;
	parsing[P_IO_FLUSH_AND][E_PIPE] = flush_string;
	parsing[P_IO_FLUSH_AND][E_SEMICOLON] = flush_string;
	parsing[P_IO_FLUSH_AND][E_NEWLINE] = flush_string;
	parsing[P_IO_FLUSH_AND][E_END] = flush_string;
}
