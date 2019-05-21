/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_blt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuppers <skuppers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:23:09 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/07 20:59:53 by skuppers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "libft.h"

static void			find_intern_variable(t_registry *shell, char **av,
						char *(*get_var)(t_registry *shell, char *name))
{
	char	*name;
	char	*tmp;

	while (*av != NULL)
	{
		if ((tmp = ft_strdup(*av)) == NULL)
			return ;
		if ((name = get_var(shell, *av)) == NULL)
		{
			ft_strupper(*av);
			if ((name = get_var(shell, *av)) == NULL)
			{
				ft_strlower(*av);
				if ((name = get_var(shell, *av)) == NULL)
					ft_dprintf(shell->cur_fd.err,
							"21sh: intern: %s: not set\n", tmp);
			}
		}
		if (name != NULL)
			ft_dprintf(shell->cur_fd.out, "%s=%s\n", *av, name, *(av + 1));
		ft_strdel(&tmp);
		++av;
	}
}

int8_t				intern_blt(t_registry *shell, char **av)
{
	uint8_t		option;

	++av;
	option = 0;
	if (*av != NULL && ft_strequ(*av, "-env") == TRUE)
	{
		++av;
		option = 1;
	}
	if (option != FALSE && shell->env == NULL)
	{
		ft_dprintf(shell->cur_fd.err,
				"21sh: intern: no environment variable\n");
		return (FAILURE);
	}
	else if (option == FALSE && shell->intern == NULL)
	{
		ft_dprintf(shell->cur_fd.err, "21sh: intern: no internal variable\n");
		return (FAILURE);
	}
	else if (*av == NULL)
		print_lst(option ? &shell->env : &shell->intern, shell->cur_fd.out);
	else
		find_intern_variable(shell, av, option ? get_env_var : get_intern_var);
	return (SUCCESS);
}
