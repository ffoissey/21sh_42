/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_blt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:11:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:54 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtin.h"

static int8_t		error_alnum_setenv(t_registry *shell)
{
	ft_dprintf(shell->cur_fd.err,
		"21sh: setenv: Variable name must contain alphanumeric characters.\n");
	return (FAILURE);
}

static int8_t		error_arg_setenv(t_registry *shell)
{
	ft_dprintf(shell->cur_fd.err,
		"21sh: setenv: Too many arguments.\n");
	return (FAILURE);
}

int8_t				setenv_blt(t_registry *shell, char **av)
{
	t_variable		*variable;

	++av;
	if (*av == NULL)
		print_lst(&shell->env, shell->cur_fd.err);
	else
	{
		variable = (t_variable *)ft_malloc(sizeof(t_variable));
		if (variable == NULL)
			return (FAILURE);
		if (ft_strcheck(av[0], ft_isalnum) == FALSE)
			return (error_alnum_setenv(shell));
		variable->name = ft_strdup(av[0]);
		variable->data = av[1] ? ft_strdup(av[1]) : ft_strdup("\0");
		add_env(shell, variable->name, variable->data);
		if (variable && variable->name && ft_strequ(variable->name, "PATH"))
			hash_blt(shell, av);
		clear_node((void **)&variable);
		ft_free(variable);
		if (av[1] != NULL && av[2] != NULL)
			return (error_arg_setenv(shell));
	}
	return (SUCCESS);
}
