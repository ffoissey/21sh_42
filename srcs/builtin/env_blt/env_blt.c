/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_blt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:11:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:53 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "sh21.h"
#include "lexer.h"

t_registry	*g_shell;

t_option				get_option_env(char *s, t_option option)
{
	while (*s != '\0')
	{
		if (*s == 'i')
			option |= I_OPT;
		else
		{
			ft_dprintf(g_shell->cur_fd.err,
							"21sh: env: -%c: invalid option\n", *s);
			ft_dprintf(g_shell->cur_fd.err, ENV_USAGE_1);
			ft_dprintf(g_shell->cur_fd.err, ENV_USAGE_2);
			return (ERROR_OPT);
		}
		s++;
	}
	return (option);
}

static void				ft_fill_with_new_value(t_registry *cpy_shell,
							char ***arg)
{
	char			*equal;
	t_variable		*variable;

	while ((equal = ft_strchr(**arg, '=')) != NULL)
	{
		variable = (t_variable *)ft_malloc(sizeof(t_variable));
		variable->name = ft_strdup(**arg);
		equal = ft_strchr(variable->name, '=');
		*equal = '\0';
		variable->data = ft_strdup(ft_strchr(**arg, '=') + 1);
		add_env(cpy_shell, variable->name, variable->data);
		(*arg)++;
		if (variable != NULL && variable->name
				&& ft_strequ(variable->name, "PATH") == TRUE)
			hash_blt(cpy_shell, NULL);
		clear_node((void **)&variable);
		ft_free(variable);
	}
}

static t_registry		*copy_registry(t_registry *shell, char ***arg,
							const t_option option)
{
	t_variable	*variable;
	t_list		*lst;
	t_registry	*cpy_shell;

	cpy_shell = (t_registry *)ft_memalloc(sizeof(*shell));
	cpy_shell = ft_memcpy(cpy_shell, shell, sizeof(*shell));
	cpy_shell->env = NULL;
	if (option == FALSE)
	{
		lst = shell->env;
		while (lst != NULL)
		{
			variable = (t_variable *)ft_malloc(sizeof(t_variable));
			variable->name = ft_strdup(((t_variable *)(lst->data))->name);
			variable->data = ft_strdup(((t_variable *)(lst->data))->data);
			add_env(cpy_shell, variable->name, variable->data);
			lst = lst->next;
			clear_node((void **)&variable);
			ft_free(variable);
		}
	}
	ft_fill_with_new_value(cpy_shell, arg);
	return (cpy_shell);
}

static char				*concat_param(char **av)
{
	char	*new_input;
	char	*arg;
	char	*tmp;

	new_input = NULL;
	while (*av != NULL)
	{
		if (*(av + 1))
			arg = ft_strjoin(*av, " ");
		else
			arg = ft_strdup(*av);
		tmp = new_input;
		new_input = ft_strjoin(tmp, arg);
		ft_strdel(&tmp);
		ft_strdel(&arg);
		av++;
	}
	return (new_input);
}

int8_t					env_blt(t_registry *shell, char **av)
{
	t_option	option;
	t_registry	*cpy_shell;
	char		*new_input;

	av++;
	option = 0;
	new_input = NULL;
	if (((option |= set_options(&av, get_option_env)) == ERROR_OPT))
		return (FAILURE);
	cpy_shell = copy_registry(shell, &av, option);
	if (*av == NULL)
		print_lst(&cpy_shell->env, shell->cur_fd.out);
	else if (*av != NULL && (new_input = concat_param(av)) != NULL)
	{
		cpy_shell->is_interactive = FALSE;
		execution_pipeline(cpy_shell, lexer(&shell->lexinfo, new_input));
		ft_strdel(&new_input);
		cpy_shell->is_interactive = TRUE;
	}
	free_lst(&(cpy_shell->env));
	ft_free(cpy_shell);
	cpy_shell = NULL;
	return (SUCCESS);
}
