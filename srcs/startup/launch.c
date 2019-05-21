/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:06:27 by skuppers          #+#    #+#             */
/*   Updated: 2019/05/07 21:00:05 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtin.h"

static int		set_shlvl(t_registry *shell)
{
	char		*shlvl;

	shlvl = get_env_var(shell, "SHLVL");
	if (shlvl == NULL)
		add_env(shell, "SHLVL", "1");
	else
	{
		shlvl = ft_itoa(ft_atoi(shlvl) + 1);
		if (shlvl == NULL)
			return (FAILURE);
		add_env(shell, "SHLVL", shlvl);
		ft_strdel(&shlvl);
	}
	return (SUCCESS);
}

static t_list	*get_env(t_list **alst, char **env)
{
	t_list		*node;
	t_variable	variable;
	size_t		pos;

	if (*env == NULL)
		return (*alst);
	pos = ft_strcspn(*env, "=");
	variable.name = ft_strsub(*env, 0, pos);
	variable.data = ft_strdup(*env + pos + 1);
	if (variable.name == NULL || variable.data == NULL)
	{
		ft_dprintf(2, "[ERROR] - Env malloc failed.\n");
		return (NULL);
	}
	if (!(node = ft_lstnew(&variable, sizeof(t_variable))))
	{
		ft_dprintf(2, "[ERROR] - Env malloc error.\n");
		return (NULL);
	}
	ft_lstaddback(alst, node);
	return (get_env(alst, ++env));
}

int8_t			set_environment(t_registry *shell, char **av, char **env)
{
	if (*av != NULL)
	{
		if (parse_arg(av, &shell->option) == FAILURE)
		{
			ft_strdel(&(shell->option.command_str));
			return (FAILURE);
		}
	}
	if ((shell->option.option & HELP_OPT) != FALSE)
	{
		shell_usage();
		ft_flush_memory();
		exit(0);
	}
	get_env(&shell->env, env);
	shell->bin_hashmap = ft_hmap_init(HMAP_BIN_SIZE);
	shell->blt_hashmap = ft_hmap_init(HMAP_BLT_SIZE);
	shell->cur_fd.in = 0;
	shell->cur_fd.out = 1;
	shell->cur_fd.err = 2;
	if (set_shlvl(shell) == FAILURE)
		return (FAILURE);
	return (hash_blt(shell, NULL));
}
