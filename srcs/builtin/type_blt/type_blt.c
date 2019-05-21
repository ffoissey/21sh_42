/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_blt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:11:50 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:54 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int8_t				type_blt(t_registry *shell, char **av)
{
	char		*path_bin;
	int8_t		error;

	av++;
	error = SUCCESS;
	while (*av != NULL)
	{
		if (ft_hmap_getdata(&shell->blt_hashmap, *av) != NULL)
			ft_dprintf(shell->cur_fd.out, "%s is a shell builtin\n", *av);
		else if ((path_bin = ft_hmap_getdata(&shell->bin_hashmap, *av))
					!= NULL)
			ft_dprintf(shell->cur_fd.out, "%s is %s\n", *av, path_bin);
		else
		{
			error = 1;
			ft_dprintf(shell->cur_fd.err, "21sh: type: %s: not found\n", *av);
		}
		av++;
	}
	return (error);
}
