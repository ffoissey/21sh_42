/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:13:51 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:04 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "resolve.h"
#include "sig.h"
#include "interface_functions.h"
#include <unistd.h>

t_list *g_job_head;

static void		get_last_bin(t_registry *shell, t_process *process, char **cmd)
{
	if (ft_hmap_getdata(&shell->bin_hashmap, process->av[0]) != NULL)
		ft_asprintf(cmd, "%s"
				, ft_hmap_getdata(&shell->bin_hashmap, process->av[0]));
	else if (process->av[0][0] == '.' || process->av[0][0] == '/')
	{
		if (access(process->av[0], F_OK) == SUCCESS
				|| access(process->av[0], X_OK) == SUCCESS)
			ft_asprintf(cmd, "%s", process->av[0]);
	}
}

static int		change_last_bin(t_process *process, t_registry *shell)
{
	char	*asp;

	asp = NULL;
	if (process->av == NULL)
		return (FAILURE);
	if (get_env_var(shell, "_") != NULL)
	{
		if (ft_hmap_getdata(&shell->blt_hashmap, process->av[0]) == NULL)
		{
			get_last_bin(shell, process, &asp);
			if (asp == NULL || change_node(&shell->env, "_", asp) == FAILURE)
				return (FAILURE);
		}
	}
	else
	{
		if (ft_hmap_getdata(&shell->blt_hashmap, process->av[0]) == NULL)
		{
			get_last_bin(shell, process, &asp);
			if (asp == NULL || s_create_node(&shell->env, "_", asp) == FAILURE)
				return (FAILURE);
		}
		ft_free(asp);
	}
	return (SUCCESS);
}

static int		update_last_bin(t_list *process_lst, t_registry *shell)
{
	t_list	*ptr;

	if (process_lst == NULL || process_lst->data == NULL)
		return (0);
	ptr = process_lst;
	while (ptr->next)
	{
		change_last_bin(ptr->data, shell);
		ptr = ptr->next;
	}
	change_last_bin(ptr->data, shell);
	return (0);
}

int				check_job(t_list *job_lst)
{
	if (job_lst == NULL)
		return (-1);
	if (job_lst->data == NULL)
		return (-1);
	if (((t_job *)job_lst->data)->process_list == NULL)
		return (-1);
	return (0);
}

void			launch_job(t_registry *shell, t_list *job_lst)
{
	t_job			*current_job;
	t_list			*process_lst;

	if (check_job(job_lst))
		return ;
	g_job_head = job_lst;
	shell_is_interactive(shell, RESTORE_TERM);
	current_job = ((t_job *)job_lst->data);
	process_lst = current_job->process_list;
	while (process_lst != NULL)
	{
		launch_process(current_job, ((t_process*)process_lst->data), shell);
		if (((t_process *)process_lst->data)->fd)
			ft_lstdelfirst(&((t_process *)process_lst->data)->fd, close_fd);
		process_lst = process_lst->next;
	}
	wait_for_job(current_job);
	update_last_bin(current_job->process_list, shell);
	shell_is_interactive(shell, SET_TERM);
}
