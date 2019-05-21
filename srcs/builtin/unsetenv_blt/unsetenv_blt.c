/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_blt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:11:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:54 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "sh21.h"

int8_t				unsetenv_blt(t_registry *shell, char **av)
{
	av++;
	if (*av == NULL)
	{
		ft_dprintf(shell->cur_fd.err, UNSETENV_USAGE);
		return (FAILURE);
	}
	if (ft_strequ(*av, "*") == TRUE)
		free_lst(&shell->env);
	else if (shell->env != NULL)
		free_node(&shell->env, *av);
	if (ft_strequ(*av, "PATH") == TRUE || ft_strequ(*av, "*") == TRUE)
		hash_blt(shell, NULL);
	return (SUCCESS);
}
