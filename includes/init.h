/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:18:11 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:22 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "parser.h"

void	init_io(t_pstate parsing);
void	init_io_filename(t_pstate parsing);
void	init_io_filename_and(t_pstate parsing);
void	init_io_flush(t_pstate parsing);
void	init_io_flush_and(t_pstate parsing);
void	init_io_redirect(t_pstate parsing);
void	init_pipe(t_pstate parsing);
void	init_io_dup_move(t_pstate parsing);
void	init_io_redirect(t_pstate parsing);
void	init_io_move(t_pstate parsing);
void	init_io_dup(t_pstate parsing);
void	init_io_heredoc_redirect(t_pstate parsing);
void	init_io_heredoc_delimiter(t_pstate parsing);
void	init_io_heredoc(t_pstate parsing);
void	init_string(t_pstate parsing);
void	init_special_string(t_pstate parsing);
void	init_flush_string(t_pstate parsing);
void	init_filename(t_pstate parsing);
void	init_start(t_pstate parsing);
void	init_separator(t_pstate parsing);
void	init_redirect(t_pstate parsing);
void	init_dup_move(t_pstate parsing);
void	init_flush_redirect(t_pstate parsing);
void	init_pipe(t_pstate parsing);
void	init_heredoc(t_pstate parsing);
void	init_heredoc_redirect(t_pstate parsing);
void	init_heredoc_delimiter(t_pstate parsing);
#endif
