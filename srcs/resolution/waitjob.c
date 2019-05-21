/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitjob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:02:11 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:05 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "resolve.h"

static int8_t	set_process_status(t_process *process, const pid_t pid,
										const int status)
{
	process->status = status;
	if (WIFSTOPPED(status) != FALSE)
		process->stopped = 1;
	else
	{
		process->completed = 1;
		if (WIFSIGNALED(status) != FALSE)
		{
			ft_dprintf(2, "[WARNING] pid %d: Terminated by signo %d.\n"
							, pid, WTERMSIG(process->status));
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

static int8_t	update_process_status(const pid_t pid, const int status)
{
	t_list		*job;
	t_list		*process;

	if (pid <= 0)
		return (FAILURE);
	job = g_job_head;
	while (job != NULL)
	{
		process = ((t_job*)job->data)->process_list;
		while (process != NULL)
		{
			if (((t_process*)process->data)->pid == pid)
			{
				return (set_process_status(
					((t_process*)process->data), pid, status));
			}
			process = process->next;
		}
		job = job->next;
	}
	ft_dprintf(2, "[WARNING]: No child process %d.\n", (const int)pid);
	return (FAILURE);
}

void			wait_for_job(t_job *job)
{
	int		status;
	pid_t	pid;

	pid = 0;
	pid = waitpid(WAIT_ANY, &status, WUNTRACED);
	while (update_process_status(pid, status) == SUCCESS
			&& job_is_stopped(job) == FALSE
			&& job_is_completed(job) == FALSE)
	{
		pid = waitpid(WAIT_ANY, &status, WUNTRACED);
	}
}
