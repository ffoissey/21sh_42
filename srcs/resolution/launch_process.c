/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:13:52 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:05 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "sig.h"
#include "resolve.h"
#include <unistd.h>

t_registry	*g_shell;

static char		**str_lst_to_tab(t_list *alst)
{
	uint32_t	i;
	size_t		size;
	t_variable	*variable;
	char		*env;
	char		**tabs;

	i = 0;
	size = ft_lstlen(alst);
	if ((tabs = (char **)ft_malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (alst != NULL)
	{
		variable = (t_variable *)alst->data;
		env = NULL;
		ft_asprintf(&env, "%s=%s", variable->name, variable->data);
		tabs[i] = env;
		alst = alst->next;
		i++;
	}
	tabs[i] = NULL;
	return (tabs);
}

static void		execute_process(t_process *process,
					t_registry *shell, char **env)
{
	define_execution_signals();
	ft_lstiter(process->fd, redirect);
	if (ft_hmap_getdata(&shell->blt_hashmap, process->av[0]) != NULL)
		exit(((t_builtin)ft_hmap_getdata(&shell->blt_hashmap
						, process->av[0]))(shell, process->av));
	else if (ft_hmap_getdata(&shell->bin_hashmap, process->av[0]) != NULL)
		execve(ft_hmap_getdata(&shell->bin_hashmap, process->av[0])
				, process->av, env);
	else if (process->av[0][0] == '.' || process->av[0][0] == '/')
		execve(process->av[0], process->av, env);
	ft_dprintf(2, "21sh: command not found: %s\n", process->av[0]);
	exit(FAILURE);
}

static int8_t	launch_builtin(t_registry *shell, t_process *process)
{
	t_builtin		f;

	if (!(f = ft_hmap_getdata(&shell->blt_hashmap, process->av[0])))
		return (FAILURE);
	shell->cur_fd.in = 0;
	shell->cur_fd.out = 1;
	shell->cur_fd.err = 2;
	ft_lstiter(process->fd, get_blt_fd);
	f(shell, process->av);
	shell->cur_fd.in = 0;
	shell->cur_fd.out = 1;
	shell->cur_fd.err = 2;
	return (SUCCESS);
}

static int8_t	is_exec(t_registry *shell, t_process *process)
{
	if (ft_hmap_getdata(&shell->blt_hashmap, process->av[0]) == NULL
			&& ft_hmap_getdata(&shell->bin_hashmap, process->av[0]) == NULL
			&& !(process->av[0][0] == '.' || process->av[0][0] == '/'))
	{
		ft_dprintf(2, "21sh: command not found: %s\n", process->av[0]);
		return (FALSE);
	}
	return (TRUE);
}

int8_t			launch_process(t_job *job, t_process *process,
						t_registry *shell)
{
	pid_t		pid;
	char		**env;

	if (is_exec(shell, process) == FALSE)
		return (SUCCESS);
	if (process->av == NULL)
		return (SUCCESS);
	if (job->process_list->next == NULL
			&& launch_builtin(shell, process) == SUCCESS)
		return (SUCCESS);
	env = str_lst_to_tab(shell->env);
	if ((pid = fork()) == SUCCESS)
		execute_process(process, shell, env);
	else if (pid < 0)
	{
		ft_dprintf(2, "[ERROR]: Fork() failed.\n");
		ft_freetab(&env);
		return (FAILURE);
	}
	ft_freetab(&env);
	process->pid = pid;
	job->pgid = job->pgid ? job->pgid : pid;
	return (SUCCESS);
}
