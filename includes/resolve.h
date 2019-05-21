/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:13:50 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:22 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVE_H
# define RESOLVE_H

# include "struct.h"

void		launch_job(t_registry *shell, t_list *joblst);
void		setup_pipes(t_job *j, t_list *p, t_filedesc *io, int pipe[2]);
void		cleanup_pipes(t_job *job, t_filedesc *io);
void		link_pipes(t_list *process, t_filedesc *io, int my_pipe[2]);
int8_t		launch_process(t_job *job, t_process *process, t_registry *shell);
void		wait_for_job(t_job *job);
uint8_t		job_is_stopped(t_job *job);
uint8_t		job_is_completed(t_job *job);
void		shell_is_interactive(t_registry *shell, uint8_t term);
void		redirect(void *data);
void		get_blt_fd(void *data);

#endif
