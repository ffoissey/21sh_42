/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_string_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:03:32 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:00 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_string(t_pstate parsing)
{
	parsing[P_STRING][E_STRING] = string_parser;
	parsing[P_STRING][E_SPSTRING] = special_string_parser;
	parsing[P_STRING][E_GREAT] = redirect_parser;
	parsing[P_STRING][E_GREATAND] = redirect_and_parser;
	parsing[P_STRING][E_LESS] = redirect_parser;
	parsing[P_STRING][E_LESSAND] = redirect_and_parser;
	parsing[P_STRING][E_DGREAT] = redirect_parser;
	parsing[P_STRING][E_DLESS] = redirect_parser;
	parsing[P_STRING][E_DLESSDASH] = redirect_parser;
	parsing[P_STRING][E_ANDGREAT] = redirect_parser;
	parsing[P_STRING][E_ANDDGREAT] = redirect_parser;
	parsing[P_STRING][E_IO_NUMBER] = io_parser;
	parsing[P_STRING][E_PIPE] = flush_string;
	parsing[P_STRING][E_SEMICOLON] = flush_string;
	parsing[P_STRING][E_NEWLINE] = flush_string;
	parsing[P_STRING][E_END] = flush_string;
}

void	init_special_string(t_pstate parsing)
{
	parsing[P_SPSTRING][E_STRING] = string_parser;
	parsing[P_SPSTRING][E_SPSTRING] = special_string_parser;
	parsing[P_SPSTRING][E_GREAT] = redirect_parser;
	parsing[P_SPSTRING][E_GREATAND] = redirect_and_parser;
	parsing[P_SPSTRING][E_LESS] = redirect_parser;
	parsing[P_SPSTRING][E_LESSAND] = redirect_and_parser;
	parsing[P_SPSTRING][E_ANDGREAT] = redirect_parser;
	parsing[P_SPSTRING][E_DLESS] = redirect_parser;
	parsing[P_SPSTRING][E_DGREAT] = redirect_parser;
	parsing[P_SPSTRING][E_DLESSDASH] = redirect_parser;
	parsing[P_SPSTRING][E_ANDDGREAT] = redirect_parser;
	parsing[P_SPSTRING][E_IO_NUMBER] = io_parser;
	parsing[P_SPSTRING][E_PIPE] = flush_string;
	parsing[P_SPSTRING][E_SEMICOLON] = flush_string;
	parsing[P_SPSTRING][E_NEWLINE] = flush_string;
	parsing[P_SPSTRING][E_END] = flush_string;
}

void	init_flush_string(t_pstate parsing)
{
	parsing[P_STRING_FLUSH][E_PIPE] = pipe_parser;
	parsing[P_STRING_FLUSH][E_END] = end_parser;
	parsing[P_STRING_FLUSH][E_SEMICOLON] = separator_parser;
}

void	init_filename(t_pstate parsing)
{
	parsing[P_FILENAME][E_STRING] = flush_redirect;
	parsing[P_FILENAME][E_SPSTRING] = flush_redirect;
	parsing[P_FILENAME][E_GREAT] = flush_redirect;
	parsing[P_FILENAME][E_GREATAND] = flush_redirect;
	parsing[P_FILENAME][E_LESS] = flush_redirect;
	parsing[P_FILENAME][E_LESSAND] = flush_redirect;
	parsing[P_FILENAME][E_DGREAT] = flush_redirect;
	parsing[P_FILENAME][E_DLESSDASH] = flush_redirect;
	parsing[P_FILENAME][E_DLESS] = flush_redirect;
	parsing[P_FILENAME][E_ANDDGREAT] = flush_redirect;
	parsing[P_FILENAME][E_IO_NUMBER] = flush_redirect;
	parsing[P_FILENAME][E_PIPE] = flush_redirect;
	parsing[P_FILENAME][E_SEMICOLON] = flush_redirect;
	parsing[P_FILENAME][E_NEWLINE] = flush_redirect;
	parsing[P_FILENAME][E_END] = flush_redirect;
}

void	init_special_filename(t_pstate parsing)
{
	parsing[P_SPFILENAME][E_STRING] = flush_redirect;
	parsing[P_SPFILENAME][E_SPSTRING] = flush_redirect;
	parsing[P_SPFILENAME][E_GREAT] = flush_redirect;
	parsing[P_SPFILENAME][E_GREATAND] = flush_redirect;
	parsing[P_SPFILENAME][E_LESS] = flush_redirect;
	parsing[P_SPFILENAME][E_LESSAND] = flush_redirect;
	parsing[P_SPFILENAME][E_DGREAT] = flush_redirect;
	parsing[P_SPFILENAME][E_DLESS] = flush_redirect;
	parsing[P_SPFILENAME][E_DLESSDASH] = flush_redirect;
	parsing[P_SPFILENAME][E_ANDDGREAT] = flush_redirect;
	parsing[P_SPFILENAME][E_IO_NUMBER] = flush_redirect;
	parsing[P_SPFILENAME][E_PIPE] = flush_redirect;
	parsing[P_SPFILENAME][E_SEMICOLON] = flush_redirect;
	parsing[P_SPFILENAME][E_NEWLINE] = flush_redirect;
	parsing[P_SPFILENAME][E_END] = flush_redirect;
}
