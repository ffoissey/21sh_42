/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:42:24 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:00 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void		set_start_token(t_graph *tab_tokens)
{
	static enum e_type tab_good_type[] = {WORD, ALL_REDIRECT, E_ASSIGN,
										E_IO_NUMBER, E_END, E_START, E_ERROR};

	tab_tokens[E_START].good_type = tab_good_type;
	tab_tokens[E_SEMICOLON].good_type = tab_good_type;
	tab_tokens[E_NEWLINE].good_type = tab_good_type;
}

void		set_redirect_token(t_graph *tab_tokens)
{
	static enum e_type tab_good_type[] = {WORD, E_ERROR};

	tab_tokens[E_GREAT].good_type = tab_good_type;
	tab_tokens[E_DGREAT].good_type = tab_good_type;
	tab_tokens[E_LESS].good_type = tab_good_type;
	tab_tokens[E_DLESS].good_type = tab_good_type;
	tab_tokens[E_GREATAND].good_type = tab_good_type;
	tab_tokens[E_LESSAND].good_type = tab_good_type;
	tab_tokens[E_ANDGREAT].good_type = tab_good_type;
	tab_tokens[E_DLESSDASH].good_type = tab_good_type;
	tab_tokens[E_ANDDGREAT].good_type = tab_good_type;
}

void		set_assign_token(t_graph *tab_tokens)
{
	static enum e_type tab_good_type[] = {WORD, E_ERROR};

	tab_tokens[E_ASSIGN].good_type = tab_good_type;
}

void		set_pipe_token(t_graph *tab_tokens)
{
	static enum e_type tab_good_type[] = {WORD, ALL_REDIRECT, E_ASSIGN,
										E_IO_NUMBER, E_ERROR};

	tab_tokens[E_PIPE].good_type = tab_good_type;
}

void		set_ionumber_token(t_graph *tab_tokens)
{
	static enum e_type tab_good_type[] = {ALL_REDIRECT, E_ERROR};

	tab_tokens[E_IO_NUMBER].good_type = tab_good_type;
}
