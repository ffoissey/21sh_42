/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:21:32 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:22 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "struct.h"

t_list		*lexer(t_lexinfo *info, char *input);
void		start_lexer(t_lexer *machine);
void		end_machine(t_lexer *machine);
void		out_lexer(t_lexer *machine);
void		string_machine(t_lexer *machine);
void		number_machine(t_lexer *machine);
void		sign_machine(t_lexer *machine);
void		expansion_machine(t_lexer *machine);
void		backslash_machine(t_lexer *machine);
void		single_quote_machine(t_lexer *machine);
void		double_quote_machine(t_lexer *machine);
void		double_sign_machine(t_lexer *machine);
void		and_machine(t_lexer *machine);
void		greater_machine(t_lexer *machine);
void		greatand_machine(t_lexer *machine);
void		lesser_machine(t_lexer *machine);
void		lessand_machine(t_lexer *machine);
void		tilde_machine(t_lexer *machine);
t_token		generate_token(t_lexer *machine);
int			create_token_data(t_lexer *machine);

/*
*****************************************************
******************* TEMP DISPLAY ********************
*****************************************************
*/

void		print_token(void *data);
void		del_token(void *token);

#endif
