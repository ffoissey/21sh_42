/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:05:16 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:00 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_start(t_pstate parsing)
{
	parsing[P_START][E_STRING] = string_parser;
	parsing[P_START][E_SPSTRING] = special_string_parser;
	parsing[P_START][E_GREAT] = redirect_parser;
	parsing[P_START][E_GREATAND] = redirect_and_parser;
	parsing[P_START][E_LESS] = redirect_parser;
	parsing[P_START][E_LESSAND] = redirect_and_parser;
	parsing[P_START][E_DGREAT] = redirect_parser;
	parsing[P_START][E_DLESS] = redirect_parser;
	parsing[P_START][E_DLESSDASH] = redirect_parser;
	parsing[P_START][E_ANDGREAT] = redirect_parser;
	parsing[P_START][E_ANDDGREAT] = redirect_parser;
	parsing[P_START][E_IO_NUMBER] = io_parser;
	parsing[P_START][E_SEMICOLON] = separator_parser;
	parsing[P_START][E_NEWLINE] = separator_parser;
	parsing[P_START][E_END] = end_parser;
}

void	init_separator(t_pstate parsing)
{
	parsing[P_SEPARATOR][E_STRING] = stop_parser;
	parsing[P_SEPARATOR][E_SPSTRING] = stop_parser;
	parsing[P_SEPARATOR][E_GREAT] = stop_parser;
	parsing[P_SEPARATOR][E_GREATAND] = stop_parser;
	parsing[P_SEPARATOR][E_LESS] = stop_parser;
	parsing[P_SEPARATOR][E_LESSAND] = stop_parser;
	parsing[P_SEPARATOR][E_DGREAT] = stop_parser;
	parsing[P_SEPARATOR][E_DLESS] = stop_parser;
	parsing[P_SEPARATOR][E_DLESSDASH] = stop_parser;
	parsing[P_SEPARATOR][E_ANDDGREAT] = stop_parser;
	parsing[P_SEPARATOR][E_SEMICOLON] = stop_parser;
	parsing[P_SEPARATOR][E_NEWLINE] = stop_parser;
	parsing[P_SEPARATOR][E_END] = end_parser;
}

void	init_redirect(t_pstate parsing)
{
	parsing[P_REDIRECT][E_STRING] = filename_parser;
	parsing[P_REDIRECT][E_SPSTRING] = filename_parser;
	parsing[P_REDIRECT_AND][E_SPSTRING] = dup_move_parser;
	parsing[P_REDIRECT_AND][E_STRING] = dup_move_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_STRING] = string_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_SPSTRING] = special_string_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_GREAT] = redirect_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_GREATAND] = redirect_and_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_LESS] = redirect_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_DLESS] = redirect_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_LESSAND] = redirect_and_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_DGREAT] = redirect_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_DLESSDASH] = redirect_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_ANDDGREAT] = redirect_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_IO_NUMBER] = io_parser;
	parsing[P_REDIRECT_FLUSH_AND][E_PIPE] = flush_string;
	parsing[P_REDIRECT_FLUSH_AND][E_SEMICOLON] = flush_string;
	parsing[P_REDIRECT_FLUSH_AND][E_NEWLINE] = flush_string;
	parsing[P_REDIRECT_FLUSH_AND][E_END] = flush_string;
}

void	init_flush_redirect(t_pstate parsing)
{
	parsing[P_REDIRECT_FLUSH][E_STRING] = string_parser;
	parsing[P_REDIRECT_FLUSH][E_SPSTRING] = special_string_parser;
	parsing[P_REDIRECT_FLUSH][E_GREAT] = redirect_parser;
	parsing[P_REDIRECT_FLUSH][E_GREATAND] = redirect_and_parser;
	parsing[P_REDIRECT_FLUSH][E_LESS] = redirect_parser;
	parsing[P_REDIRECT_FLUSH][E_DLESS] = redirect_parser;
	parsing[P_REDIRECT_FLUSH][E_LESSAND] = redirect_and_parser;
	parsing[P_REDIRECT_FLUSH][E_DGREAT] = redirect_parser;
	parsing[P_REDIRECT_FLUSH][E_DLESSDASH] = redirect_parser;
	parsing[P_REDIRECT_FLUSH][E_ANDDGREAT] = redirect_parser;
	parsing[P_REDIRECT_FLUSH][E_IO_NUMBER] = io_parser;
	parsing[P_REDIRECT_FLUSH][E_PIPE] = flush_string;
	parsing[P_REDIRECT_FLUSH][E_SEMICOLON] = flush_string;
	parsing[P_REDIRECT_FLUSH][E_NEWLINE] = flush_string;
	parsing[P_REDIRECT_FLUSH][E_END] = flush_string;
}

void	init_dup_move(t_pstate parsing)
{
	parsing[P_DUP_MOVE][E_STRING] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_SPSTRING] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_GREAT] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_GREATAND] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_LESS] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_LESSAND] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_DGREAT] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_ANDDGREAT] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_IO_NUMBER] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_PIPE] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_SEMICOLON] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_NEWLINE] = flush_redirect_and;
	parsing[P_DUP_MOVE][E_END] = flush_redirect_and;
}
