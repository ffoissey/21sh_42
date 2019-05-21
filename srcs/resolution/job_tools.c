/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:18:25 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:04 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "sig.h"
#include "interface_functions.h"
#include <unistd.h>

t_list	*g_job_head;

uint8_t		job_is_stopped(t_job *job)
{
	t_list		*process;

	process = job->process_list;
	while (process != NULL)
	{
		if (((t_process *)process->data)->completed == FALSE
				&& ((t_process *)process->data)->stopped == FALSE)
			return (FALSE);
		process = process->next;
	}
	return (TRUE);
}

uint8_t		job_is_completed(t_job *job)
{
	t_list		*process;

	process = job->process_list;
	while (process != NULL)
	{
		if (((t_process*)process->data)->completed == FALSE)
			return (FALSE);
		process = process->next;
	}
	return (TRUE);
}

void		shell_is_interactive(t_registry *shell, uint8_t term)
{
	if (shell->is_interactive == TRUE)
	{
		if (term == RESTORE_TERM)
		{
			restore_term_behavior(shell);
			define_execution_signals();
		}
		else if (term == SET_TERM)
		{
			set_term_behavior(shell);
			define_ign_signals();
		}
	}
}

void		redirect(void *data)
{
	t_filedesc *fd;

	fd = data;
	if (fd->action & FD_CLOSE)
		close(fd->second);
	else if (fd->first != fd->second)
		dup2(fd->first, fd->second);
}

void		get_blt_fd(void *data)
{
	t_filedesc *fd;

	fd = data;
	if (fd->second == 0)
		g_shell->cur_fd.in = (fd->action & FD_CLOSE) ? -1 : fd->first;
	else if (fd->second == 2)
		g_shell->cur_fd.err = (fd->action & FD_CLOSE) ? -1 : fd->first;
	else
		g_shell->cur_fd.out = (fd->action & FD_CLOSE) ? -1 : fd->first;
}
