/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:39:31 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:22 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"

/*
*****************************************************
****************** GRAMMAR PARSER  ******************
*****************************************************
*/

int8_t		parser(t_graph *graph, t_list *lst);
void		generate_graph(t_registry *shell);
void		set_start_token(t_graph *tab_tokens);
void		set_word_token(t_graph *tab_tokens);
void		set_redirect_token(t_graph *tab_tokens);
void		set_assign_token(t_graph *tab_tokens);
void		set_pipe_token(t_graph *tab_tokens);
void		set_ionumber_token(t_graph *tab_tokens);

/*
*************** GRAMMAR PARSER DEBUG
*/

void		print_token_debug(t_token *token);
void		print_arrow_debug(int which);
void		print_error_debug(enum e_type type, int which);
void		print_result_debug(int which);

/*
*****************************************************
**************** APPLICATION PARSER *****************
*****************************************************
*/

void		init_parser(t_registry *shell, t_parser *parse);
void		init_parsing(t_pstate parsing);
void		init_process(t_process *process);
t_list		*parser_state(t_pstate parsing, t_parser *parse);
void		start_parser(t_parser *parse);
void		separator_parser(t_parser *parse);
void		stop_parser(t_parser *parse);
void		end_parser(t_parser *parse);
void		error_parser(t_parser *parse);

void		string_parser(t_parser *parse);
void		special_string_parser(t_parser *parse);
void		flush_string(t_parser *parse);

void		redirect_parser(t_parser *parse);
void		redirect_and_parser(t_parser *parse);
void		pipe_parser(t_parser *parse);
void		filename_parser(t_parser *parse);
void		dup_move_parser(t_parser *parse);
void		flush_redirect(t_parser *parse);
void		flush_redirect_and(t_parser *parse);

void		io_parser(t_parser *parse);
void		io_redirect_parser(t_parser *parse);
void		io_redirect_and_parser(t_parser *parse);
void		io_dup_move_parser(t_parser *parse);
void		io_filename_parser(t_parser *parse);
void		io_and_redirect_flush(t_parser *parse);
void		io_redirect_flush(t_parser *parse);

void		heredoc_parser(t_parser *parse);
void		io_heredoc_parser(t_parser *parse);
void		heredoc_delimiter(t_parser *parse);

void		delete_process(void *data);
char		*expand_string(t_list *lst, char *str);
char		*string_expansion(t_parser *parse, char *str);
char		*tilde(t_parser *parse, char *str);
char		*variable_expansion(t_parser *parse, char *str);
void		quote_removal(char *str);
char		character_swap(char swapped);
t_quote		select_quoting(t_quote quote, char c);
int			is_ionumber(t_parser *parse, char *str);
void		check_filename(t_parser *parse);
t_type		pop_token_type(t_stack *stack);
char		*pop_token_data(t_stack *stack);
void		get_token(t_parser *parse);
void		generate_filedesc(t_parser *parse, int first, int second
					, int action);
#endif
