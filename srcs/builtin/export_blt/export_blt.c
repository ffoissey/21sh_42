/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_blt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:11:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:53 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "sh21.h"

t_registry *g_shell;

t_option			get_option_export(char *s, t_option option)
{
	while (*s)
	{
		if (*s == 'p')
			option |= P_OPT;
		else
		{
			ft_dprintf(g_shell->cur_fd.err,
						"21sh: export: -%c: invalid option\n", *s);
			ft_dprintf(g_shell->cur_fd.err, EXPORT_USAGE);
			return (ERROR_OPT);
		}
		s++;
	}
	return (option);
}

static void			add_var_and_rehash(t_registry *shell,
						t_variable *variable, char **av)
{
	if (variable->data)
		add_env(shell, variable->name, variable->data);
	if (variable && variable->name && ft_strequ(variable->name, "PATH"))
		hash_blt(shell, av);
	clear_node((void **)&variable);
}

int8_t				export_blt(t_registry *shell, char **av)
{
	t_variable	*variable;
	char		*equal;
	t_option	option;

	av++;
	option = 0;
	if (((option |= set_options(&av, get_option_export)) == ERROR_OPT))
		return (FAILURE);
	while (*av != NULL)
	{
		if ((variable = (t_variable *)ft_malloc(sizeof(t_variable))) == NULL)
			return (FAILURE);
		variable->name = ft_strdup(*av);
		if ((equal = ft_strchr(*av, '=')) != NULL)
		{
			equal = ft_strchr(variable->name, '=');
			*equal = '\0';
			variable->data = ft_strdup(ft_strchr(*av, '=') + 1);
		}
		else
			variable->data = ft_strdup(get_intern_var(shell, variable->name));
		add_var_and_rehash(shell, variable, av++);
		ft_free(variable);
	}
	return (SUCCESS);
}
